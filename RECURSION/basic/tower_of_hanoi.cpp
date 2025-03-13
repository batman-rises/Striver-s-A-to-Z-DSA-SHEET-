// part 1

void TOH(int n, char s, char h, char d)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        cout << s << "->" << d << endl;
        return;
    }
    TOH(n - 1, s, d, h);
    cout << s << "->" << d << endl;
    TOH(n - 1, h, s, d);
}

// part 2

int func(int n, char s, char h, char d)
{
    if (n == 0)
        return 0;

    int moves = 0;
    moves += func(n - 1, s, d, h);
    moves += 1;
    moves += func(n - 1, h, s, d);
    return moves;
}