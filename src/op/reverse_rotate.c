/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:35 by ededemog          #+#    #+#             */
/*   Updated: 2024/03/20 19:26:20 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_list **stack_a, bool status)
{
	t_list	*last_node;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last_node = ft_lstlast(*stack_a);
	last_node->prev->next = NULL;
	last_node->next = *stack_a;
	last_node->prev = NULL;
	*stack_a = last_node;
	if (!status)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, bool status)
{
	t_list	*last_node;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last_node = ft_lstlast(*stack_b);
	last_node->prev->next = NULL;
	last_node->next = *stack_b;
	last_node->prev = NULL;
	*stack_b = last_node;
	if (!status)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, bool status)
{
	rra(stack_a, status);
	rrb(stack_b, status);
	if (!status)
		write(1, "rrr\n", 4);
}

#include <stdio/h>

void push(t_list **head_ref, int new_data) {
    t_list *new_node = (t_list*)malloc(sizeof(t_list));
    new_node->content = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if (*head_ref != NULL) (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

// Fonction pour imprimer la pile
void printStack(t_list *node) {
    while (node != NULL) {
        printf("%d ", node->content);
        node = node->next;
    }
    printf("\n");
}

// Fonction de test pour les fonctions rra, rrb, et rrr
void testReverseRotateFunctions() {
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    // Ajout de nœuds à la pile A
    push(&stack_a, 1);
    push(&stack_a, 2);
    push(&stack_a, 3);

    // Ajout de nœuds à la pile B
    push(&stack_b, 4);
    push(&stack_b, 5);
    push(&stack_b, 6);

    printf("Pile A avant rotation inverse : ");
    printStack(stack_a);
    rra(&stack_a, false); // Appel de la fonction rra
    printf("Pile A après rotation inverse : ");
    printStack(stack_a);

    printf("Pile B avant rotation inverse : ");
    printStack(stack_b);
    rrb(&stack_b, false); // Appel de la fonction rrb
    printf("Pile B après rotation inverse : ");
    printStack(stack_b);

    printf("Piles A et B avant rotation inverse simultanée : ");
    printStack(stack_a);
    printStack(stack_b);
    rrr(&stack_a, &stack_b, false); // Appel de la fonction rrr
    printf("Piles A et B après rotation inverse simultanée : ");
    printStack(stack_a);
    printStack(stack_b);
}

int main() {
    testReverseRotateFunctions();
    return 0;
}