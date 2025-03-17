#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's define a struct for representing pixels - this makes the code way more readable
typedef struct {
    int r, g, b;  // Red, green, blue values
} PixelStack;

// func. declarations
PixelStack** ReadImg(int *width, int *height);
void ApplySepiaFilter(PixelStack **image, int width, int height);
void Flip(PixelStack **image, int width, int height);
void PrintImg(PixelStack **image, int width, int height);
void FreeImg(PixelStack **image, int height);

int main(int argc, char *argv[]) {
    int i;
    int applyFlip = 0;
    int sepiaFlag = 0;
    int width, height;
    
    // Parse command line arguments
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            applyFlip = 1;
        } else if (strcmp(argv[i], "-s") == 0) {
            sepiaFlag = 1;
        }
    }
    
    // Read the image from stdin
    PixelStack **image = ReadImg(&width, &height);
    
    // Apply transformations if requested
    // Order matters here - if both are applied, the image is flipped first, then sepia is applied
    if (applyFlip) {
        Flip(image, width, height);
    }
    
    if (sepiaFlag) {
        ApplySepiaFilter(image, width, height);
    }
    
    // Output the transformed image
    PrintImg(image, width, height);
    
    // Free memory
    FreeImg(image, height);
    
    return 0;
}

// This function reads an image from stdin and returns a 2D array of pixels
PixelStack** ReadImg(int *width, int *height) {
    char format[3];
    int colorMax;
    int i, j;
    PixelStack **image;
    
    // Read header
    scanf("%s", format);    // Should be "P3"
    scanf("%d %d", width, height);
    scanf("%d", &colorMax);  // Should be 255
    
    // Allocate memory for the image - we're going row by row here
    image = (PixelStack**)malloc(*height * sizeof(PixelStack*));
    for (i = 0; i < *height; i++) {
        // Each row has width pixels
        image[i] = (PixelStack*)malloc(*width * sizeof(PixelStack));
    }
    
    // Read the pixels - basically just looping through each row and column
    for (i = 0; i < *height; i++) {
        for (j = 0; j < *width; j++) {
            scanf("%d %d %d", &image[i][j].r, &image[i][j].g, &image[i][j].b);
        }
    }
    
    return image;
}

// This function applies the sepia filter to the image
void ApplySepiaFilter(PixelStack **image, int width, int height) {
    int i, j;
    int new_r, new_g, new_b;
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Calculate new RGB values using the sepia formulas
            new_r = (int)(0.393 * image[i][j].r + 0.769 * image[i][j].g + 0.189 * image[i][j].b);
            new_g = (int)(0.349 * image[i][j].r + 0.686 * image[i][j].g + 0.168 * image[i][j].b);
            new_b = (int)(0.272 * image[i][j].r + 0.534 * image[i][j].g + 0.131 * image[i][j].b);
            
            // Cap values at 255 - we don't want to overflow
            image[i][j].r = (new_r > 255) ? 255 : new_r;
            image[i][j].g = (new_g > 255) ? 255 : new_g;
            image[i][j].b = (new_b > 255) ? 255 : new_b;
        }
    }
}

// This function flips the image horizontally
void Flip(PixelStack **image, int width, int height) {
    int i, j;
    PixelStack temp;
    
    // For each row, we swap pixels from the left and right sides
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            // Swap pixels at positions j and width-j-1
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// This function prints the image to stdout in PPM format
void PrintImg(PixelStack **image, int width, int height) {
    int i, j;
    
    // Print header
    printf("P3\n");
    printf("%d %d\n", width, height);
    printf("255\n");
    
    // Print pixels - keeping the same format as the input
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d %d %d", image[i][j].r, image[i][j].g, image[i][j].b);
            // Add space between pixels, but not after the last pixel in a row
            printf(" ");
        }
        printf("\n");  // Newline after each row
    }
}

// This function frees the memory allocated for the image
void FreeImg(PixelStack **image, int height) {
    int i;
    
    // Gotta free everything we malloc'd or we'll leak memory
    for (i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}