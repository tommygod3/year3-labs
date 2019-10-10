int main ()
{
    int x = 10;
    int* y = &x;
    int* z = new int(10);
    x++;


    delete z;
    //would break if: delete y;

    return 0;
}