void ft_putchar(char ch);

/**
 * This function is a while loop solution
 */
void rush(int x, int y) {
    int colX = 1, rowY = 1;
    char printedChar = ' ';

    while (rowY <= y) {
        while (colX <= x) {
            printedChar = ' ';
            // check if we are on the first row & first collumn or
            // on the last row & last column but only the row and column counts are greater than one
            if ((colX == 1 && rowY == 1) || (colX == x && rowY == y && colX > 1 && rowY > 1)) printedChar = 'A';
            // check if we are on the first row & last column or
            // on the last row & first column
            else if ((colX == x && rowY == 1) || (colX == 1 && rowY == y)) printedChar = 'C';
            // check if we are on the first and last row, or first and last column
            else if (colX == 1 || colX == x || rowY == 1 || rowY == y) printedChar = 'B';
            ft_putchar(printedChar);
            // increment the column counter by 1
            colX++;
        }

        // increment the row counter by 1, and reset the column counter
        rowY++, colX = 1;
        ft_putchar('\n');
    }
}