bool palin(int n)
{
    int rev = 0, temp = n;
    while (temp > 0)
    {
        int ld = temp % 10;
        rev = (rev * 10) + ld;
        temp = temp / 10;
    }
    return (n == rev)
}