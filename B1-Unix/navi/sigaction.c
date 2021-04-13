/*
** EPITECH PROJECT, 2020
** sigaction
** File description:
** file 1
*/

#include "include/navy.h"

void init_user_connection(int nb, siginfo_t *info, void *null)
{
    if (nb == SIGUSR1) {
        store->enemy_pid = info->si_pid;
        kill(store->enemy_pid, SIGUSR2);
    }
    if (nb == SIGUSR2) {
        if (info->si_pid == store->enemy_pid)
            store->lock_enemy_pid_ok = 1;
    }
}

void receive_attack(int nb, siginfo_t *info, void *null)
{
    if (info->si_pid != store->enemy_pid)
        return;
    if (nb == SIGUSR1 && store->attack_statue == 0) {
        store->enemy_attack_let += 1;
    }
    if (nb == SIGUSR1 && store->attack_statue == 1) {
        store->enemy_attack_nb += 1;
    }
    if (nb == SIGUSR2) {
        store->attack_statue += 1;
    }
}

void stop_attack(int nb, siginfo_t *info, void *null)
{
    if (info->si_pid != store->enemy_pid)
        return;
    if (nb == SIGUSR1) {
        my_printf("hit\n");
        store->enemy_map[store->enemy_attack_let][store->enemy_attack_nb] = 'x';
    }
    if (nb == SIGUSR2) {
        my_printf("missed\n");
        if (store->enemy_map[store->enemy_attack_let][store->enemy_attack_nb]
            != 'x')
            store->enemy_map[store->enemy_attack_let][store->enemy_attack_nb]
            = 'o';
    }
    store->attack_statue = 1;
}