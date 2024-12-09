#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to draw the triangle
void drawTriangle(int midx, int midy, float x1, float y1, float x2, float y2, float x3, float y3, int color) {
    setcolor(color);
    line(midx + x1, midy - y1, midx + x2, midy - y2);
    line(midx + x2, midy - y2, midx + x3, midy - y3);
    line(midx + x3, midy - y3, midx + x1, midy - y1);
}

// Function for Translation
void translateTriangle(int midx, int midy, float *x1, float *y1, float *x2, float *y2, float *x3, float *y3) {
    float tx, ty;
    printf("Enter translation factors (tx, ty): ");
    scanf("%f%f", &tx, &ty);

    *x1 += tx;
    *y1 += ty;
    *x2 += tx;
    *y2 += ty;
    *x3 += tx;
    *y3 += ty;

    drawTriangle(midx, midy, *x1, *y1, *x2, *y2, *x3, *y3, RED);
}

// Function for Rotation
void rotateTriangle(int midx, int midy, float *x1, float *y1, float *x2, float *y2, float *x3, float *y3) {
    float angle, radianAngle;
    float tempX, tempY, pivotX = *x2, pivotY = *y2;

    printf("Enter angle of rotation (in degrees): ");
    scanf("%f", &angle);
    radianAngle = (angle * M_PI) / 180.0;

    // Rotate point 1
    tempX = pivotX + (*x1 - pivotX) * cos(radianAngle) - (*y1 - pivotY) * sin(radianAngle);
    tempY = pivotY + (*x1 - pivotX) * sin(radianAngle) + (*y1 - pivotY) * cos(radianAngle);
    *x1 = tempX;
    *y1 = tempY;

    // Rotate point 2
    tempX = pivotX + (*x2 - pivotX) * cos(radianAngle) - (*y2 - pivotY) * sin(radianAngle);
    tempY = pivotY + (*x2 - pivotX) * sin(radianAngle) + (*y2 - pivotY) * cos(radianAngle);
    *x2 = tempX;
    *y2 = tempY;

    // Rotate point 3
    tempX = pivotX + (*x3 - pivotX) * cos(radianAngle) - (*y3 - pivotY) * sin(radianAngle);
    tempY = pivotY + (*x3 - pivotX) * sin(radianAngle) + (*y3 - pivotY) * cos(radianAngle);
    *x3 = tempX;
    *y3 = tempY;

    drawTriangle(midx, midy, *x1, *y1, *x2, *y2, *x3, *y3, GREEN);
}

// Function for Scaling
void scaleTriangle(int midx, int midy, float *x1, float *y1, float *x2, float *y2, float *x3, float *y3) {
    float sx, sy;
    printf("Enter scaling factors (sx, sy): ");
    scanf("%f%f", &sx, &sy);

    *x1 *= sx;
    *y1 *= sy;
    *x2 *= sx;
    *y2 *= sy;
    *x3 *= sx;
    *y3 *= sy;

    drawTriangle(midx, midy, *x1, *y1, *x2, *y2, *x3, *y3, BLUE);
}

int main() {
    int gd = DETECT, gm, midx, midy, choice;
    float x1, y1, x2, y2, x3, y3;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    // Draw axes
    line(midx, 0, midx, getmaxy());
    line(0, midy, getmaxx(), midy);

    // Input initial triangle coordinates
    printf("Enter the coordinates of the triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);

    drawTriangle(midx, midy, x1, y1, x2, y2, x3, y3, WHITE);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Translation\n");
        printf("2. Rotation\n");
        printf("3. Scaling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        cleardevice();
        line(midx, 0, midx, getmaxy());
        line(0, midy, getmaxx(), midy);

        switch (choice) {
            case 1:
                translateTriangle(midx, midy, &x1, &y1, &x2, &y2, &x3, &y3);
                break;

            case 2:
                rotateTriangle(midx, midy, &x1, &y1, &x2, &y2, &x3, &y3);
                break;

            case 3:
                scaleTriangle(midx, midy, &x1, &y1, &x2, &y2, &x3, &y3);
                break;

            case 4:
                closegraph();
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    getch();
    closegraph();
    return 0;
}