void swap_by_value(int a, int b)
{
    int temp = a;
    a = b;
    b = a;
    return;
}
void swap_by_reference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int main()
{
    int a = 10;
    int b = 15;
    swap_by_value(a, b);
    swap_by_reference(&a, &b);
    return 0;
}