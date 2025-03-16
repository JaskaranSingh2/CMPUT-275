#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's define a struct for representing pixels - this makes the code way more readable
typedef struct {
    int r, g, b;  // Red, green, blue values
} Pixel_Stack;

// func. declarations
Pixel_Stack** read_image(int *width, int *height);
void apply_sepia_filter(Pixel_Stack **image, int width, int height);
void flip_image(Pixel_Stack **image, int width, int height);
void print_image(Pixel_Stack **image, int width, int height);
void free_image(Pixel_Stack **image, int height);

int main(int argc, char *argv[]) {
    int i;
    int apply_flip = 0;
    int apply_sepia_flag = 0;
    int width, height;
    
    // Parse command line arguments
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            apply_flip = 1;
        } else if (strcmp(argv[i], "-s") == 0) {
            apply_sepia_flag = 1;
        }
    }
    
    // Read the image from stdin
    Pixel_Stack **image = read_image(&width, &height);
    
    // Apply transformations if requested
    // Order matters here - if both are applied, the image is flipped first, then sepia is applied
    if (apply_flip) {
        flip_image(image, width, height);
    }
    
    if (apply_sepia_flag) {
        apply_sepia_filter(image, width, height);
    }
    
    // Output the transformed image
    print_image(image, width, height);
    
    // Free memory
    free_image(image, height);
    
    return 0;
}

// This function reads an image from stdin and returns a 2D array of pixels
Pixel_Stack** read_image(int *width, int *height) {
    char format[3];
    int max_color;
    int i, j;
    Pixel_Stack **image;
    
    // Read header
    scanf("%s", format);    // Should be "P3"
    scanf("%d %d", width, height);
    scanf("%d", &max_color);  // Should be 255
    
    // Allocate memory for the image - we're going row by row here
    image = (Pixel_Stack**)malloc(*height * sizeof(Pixel_Stack*));
    for (i = 0; i < *height; i++) {
        // Each row has width pixels
        image[i] = (Pixel_Stack*)malloc(*width * sizeof(Pixel_Stack));
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
void apply_sepia_filter(Pixel_Stack **image, int width, int height) {
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
void flip_image(Pixel_Stack **image, int width, int height) {
    int i, j;
    Pixel_Stack temp;
    
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
void print_image(Pixel_Stack **image, int width, int height) {
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
            if (j < width - 1) {
                printf(" ");
            }
        }
        printf("\n");  // Newline after each row
    }
}

// This function frees the memory allocated for the image
void free_image(Pixel_Stack **image, int height) {
    int i;
    
    // Gotta free everything we malloc'd or we'll leak memory
    for (i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}