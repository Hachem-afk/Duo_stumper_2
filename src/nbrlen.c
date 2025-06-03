/*
** EPITECH PROJECT, 2024
** nbr_len
** File description:
** Return the len of an int
*/

int intlen(int nb)
{
    int count = 0;

    if (nb < 0) {
        count += 1;
        nb *= -1;
    }
    while (nb > 9) {
        count++;
        nb /= 10;
    }
    return count + 1;
}
