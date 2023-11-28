int countSetBits(int num)
{
    int count = 0;
    while (num) 
    {
        count += num & 1;
        num = num >> 1;
    }

    return count;
}