/*
** EPITECH PROJECT, 2020
** attack
** File description:
** file 1
*/

#include "include/navy.h"

int get_let_in_map(int let)
{
    if (let == 0)
        return (2);
    if (let == 1)
        return (4);
    if (let == 2)
        return (6);
    if (let == 3)
        return (8);
    if (let == 4)
        return (10);
    if (let == 5)
        return (12);
    if (let == 6)
        return (14);
    return (16);
}

void send_cord(my_struct *store, char *buff, struct sigaction sig)
{
    for (int let = 0; let < convert_let(buff[0]); let += 1) {
        kill(store->enemy_pid, SIGUSR1);
        usleep(100);
    }
    kill(store->enemy_pid, SIGUSR2);
    usleep(100);
    for (int nb = 0; nb < (buff[1] - '0'); nb += 1) {
        kill(store->enemy_pid, SIGUSR1);
        usleep(100);
    }
    kill(store->enemy_pid, SIGUSR2);
    store->enemy_attack_let = get_let_in_map(buff[0] - 'A');
    store->enemy_attack_nb = buff[1] - '0' + 1;
    my_printf("%c%c: ", buff[0], buff[1]);
    while (store->attack_statue != 1) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
}

void hit_or_not(my_struct *store)
{
    if (store->ally_map[store->enemy_attack_let][store->enemy_attack_nb] != '.'
        && store->ally_map[store->enemy_attack_let][store->enemy_attack_nb]
        != 'o'
        && store->ally_map[store->enemy_attack_let][store->enemy_attack_nb]
        != 'x') {
        store->ally_map[store->enemy_attack_let][store->enemy_attack_nb] = 'x';
        my_printf("hit\n");
        kill(store->enemy_pid, SIGUSR1);
    } else {
        if (store->ally_map[store->enemy_attack_let][store->enemy_attack_nb]
            != 'x')
            store->ally_map[store->enemy_attack_let][store->enemy_attack_nb]
            = 'o';
        my_printf("missed\n");
        kill(store->enemy_pid, SIGUSR2);
    }
}

void make_attack(my_struct *store)
{
    char *buff = NULL;
    size_t buff_size = 0;
    size_t length;
    int lock = 0;
    struct sigaction sig = {0};

    sig.sa_sigaction = &stop_attack;
    sig.sa_flags = SA_SIGINFO;
    while (lock != 1) {
        my_printf("\nattack: ");
        length = getline(&buff, &buff_size, stdin);
        if (length != 3 || verif_let(buff[0]) == 84
            || verif_nb(buff[1], 0) == 84)
            my_printf("wrong position");
        else
            lock = 1;
    }
    send_cord(store, buff, sig);
    reinit_struct(store);
    free(buff);
}

void waiting_attack(my_struct *store)
{
    struct sigaction sig = {0};

    sig.sa_sigaction = &receive_attack;
    sig.sa_flags = SA_SIGINFO;
    my_printf("\nwaiting for enemy's attack...\n");
    while (store->attack_statue != 2) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
    my_printf("%c%d: ", store->enemy_attack_let + 'A', store->enemy_attack_nb);
    store->enemy_attack_let = get_let_in_map(store->enemy_attack_let);
    store->enemy_attack_nb += 1;
    hit_or_not(store);
    reinit_struct(store);
}