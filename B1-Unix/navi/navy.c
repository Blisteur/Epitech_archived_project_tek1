/*
** EPITECH PROJECT, 2020
** navy
** File description:
** file 1
*/

#include "include/navy.h"

void user_one_setup(void)
{
    pid_t pid;
    struct sigaction sig = {0};

    pid = getpid();
    my_printf("my_pid: %d\n", pid);
    my_printf("waiting for enemy connection...\n");
    sig.sa_sigaction = &init_user_connection;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    pause();
    my_printf("\nenemy connected\n");
}

void user_two_setup(my_struct *store)
{
    pid_t pid;
    struct sigaction sig = {0};

    pid = getpid();
    my_printf("my_pid: %d\n", pid);
    sig.sa_sigaction = &init_user_connection;
    sig.sa_flags = SA_SIGINFO;
    kill(store->enemy_pid, SIGUSR1);
    while (store->lock_enemy_pid_ok == 0)
        sigaction(SIGUSR2, &sig, NULL);
    my_printf("successfully connected\n");
}

void navy(my_struct *store)
{
    if (store->usr == 1)
        user_one_setup();
    else
        user_two_setup(store);
    while (store->game_stade == 0) {
        print_map(store);
        if (store->usr == 2)
            waiting_attack(store);
        else
            make_attack(store);
        if (verif_end_game(store) == 1)
            return;
        if (store->usr == 1)
            waiting_attack(store);
        else
            make_attack(store);
        if (verif_end_game(store) == 1)
            return;
    }
}