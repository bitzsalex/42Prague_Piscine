void ft_putchar(char ch);
char getPrintedChar(int colX, int rowY, int x, int y);

char getPrintedChar(int colX, int rowY, int x, int y) {
    char printedChar = ' ';

    // check if we are on the first row & first collumn or
    // on the last row & last column but only the row and column counts are greater than one
    if ((colX == 1 && rowY == 1) || (colX == x && rowY == y && colX > 1 && rowY > 1)) printedChar = '/';
    // check if we are on the first row & last column or
    // on the last row & first column
    else if ((colX == x && rowY == 1) || (colX == 1 && rowY == y)) printedChar = '\\';
    // check if we are on the first and last row, or first and last column
    else if (colX == 1 || colX == x || rowY == 1 || rowY == y) printedChar = '*';

    return printedChar;
}

/**
 * This function is a while loop solution
 */
void rush01(int x, int y) {
    int colX = 1, rowY = 1;
    char printedChar = ' ';

    while (rowY <= y) {
        while (colX <= x) {
            printedChar = getPrintedChar(colX, rowY, x, y);
            ft_putchar(printedChar);
            // increment the column counter by 1
            colX++;
        }

        // increment the row counter by 1, and reset the column counter
        rowY++, colX = 1;
        ft_putchar('\n');
    }
}


/**
 * This function is a do...while loop solution
 */
void rush01D(int x, int y) {
    int colX = 1, rowY = 1;
    char printedChar = ' ';

    do {
        do {
            printedChar = getPrintedChar(colX, rowY, x, y);
            ft_putchar(printedChar);
            colX++;
        } while (colX <= x);

        // increment the row counter by 1, and reset the column counter
        rowY++, colX = 1;
        ft_putchar('\n');
    } while (rowY <= y);
}


/**
 * This function is a for loop solution
 */
void rush01F(int x, int y) {
    int colX = 1, rowY = 1;
    char printedChar = ' ';

    for (int rowY = 1; rowY <= y; rowY++) {
        for (int colX = 1; colX <= x; colX++) {
            printedChar = getPrintedChar(colX, rowY, x, y);
            ft_putchar(printedChar);
        }
        ft_putchar('\n');
    }
}