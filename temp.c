
{
    t_list *new;
    t_list *node;

    new = (t_list *)(malloc)(sizeof(t_list));
    if (new == 0)
        return (0);
    while (lst != 0)
    {
        f(lst->content);
        new = lst;
        lst = lst->next;
    }
    return (new);
}
// del과 free는 언제 쓰이는 것?
