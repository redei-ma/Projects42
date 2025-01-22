#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int			value;
	struct s_list *next;
	struct s_list *prev;
}	t_list;

int		ft_natoi(char *str);
t_list	*ft_lstnew(char *av);
t_list	*ft_lstcreation(char **av);
int		checkduplicate(t_list *lst);
int		ft_algoritmo(t_list **head_a, t_list **head_b);
int		ft_abs(int x);

void	ft_sa(t_list **head_a);
void	ft_sb(t_list **head_b);
void	ft_ss(t_list **head_a, t_list **head_b);
void	ft_pa(t_list **head_a, t_list **head_b);
void	ft_pb(t_list **head_a, t_list **head_b);
void	ft_ra(t_list **head_a);
void	ft_rb(t_list **head_b);
void	ft_rr(t_list **head_a, t_list **head_b);
void	ft_rra(t_list **head_a);
void	ft_rrb(t_list **head_b);
void	ft_rrr(t_list **head_a, t_list **head_b);


int		check_finish(t_list *head_a, t_list *head_b);
void	tidy_up(t_list **head_a);
int		*ft_weight_b(t_list *head_b);
int		*ft_weight_a(t_list *head_a, t_list *head_b);
int		pos_calc(t_list	*head, int num, int size);
int		ft_minor(t_list *head);
void	make_move(int *moves, t_list **head_a, t_list **head_b);



void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_lstsize(t_list *lst);
void	ft_lstprint(t_list *head_a, t_list *head_b);

#endif