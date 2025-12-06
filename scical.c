#include <stdio.h>
#include <math.h>
#include <stdlib.h> // For exit()

#define PI 3.14159265 // Define PI for degree-to-radian conversion

int main() {
    int choice, num1_int, num2_int;
    double num1_double, num2_double, result;

    do {
        printf("\n===== Menu-Driven Calculator =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus (for integers)\n");
        printf("6. Square Root\n");
        printf("7. Power (Exponentiation)\n");
        printf("8. Factorial\n");
        printf("9. Trigonometric Functions (Sine, Cosine, Tangent)\n");
        printf("10. Exit\n");
        printf("Enter your choice (1-10): ");
        scanf("%d", &choice);

        // Exit condition
        if (choice == 10) {
            printf("Exiting Calculator.\n");
            exit(0);
        }

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1_double, &num2_double);
                if (choice == 1) result = num1_double + num2_double;
                else if (choice == 2) result = num1_double - num2_double;
                else if (choice == 3) result = num1_double * num2_double;
                else {
                    if (num2_double != 0) {
                        result = num1_double / num2_double;
                    } else {
                        printf("Error: Division by zero is not allowed.\n");
                        continue; // Skip the result print for error
                    }
                }
                printf("Result = %.4lf\n", result);
                break;

            case 5:
                printf("Enter two integers (num1 %% num2): ");
                scanf("%d %d", &num1_int, &num2_int);
                if (num2_int != 0) {
                    result = num1_int % num2_int;
                    printf("Result = %d\n", (int)result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;

            case 6:
                printf("Enter a number to find the square root: ");
                scanf("%lf", &num1_double);
                if (num1_double >= 0) {
                    result = sqrt(num1_double);
                    printf("Result = %.4lf\n", result);
                } else {
                    printf("Error: Square root of a negative number is not possible.\n");
                }
                break;

            case 7:
                printf("Enter base and exponent (base^exponent): ");
                scanf("%lf %lf", &num1_double, &num2_double);
                result = pow(num1_double, num2_double);
                printf("Result = %.4lf\n", result);
                break;

            case 8:
                printf("Enter a non-negative integer for factorial: ");
                scanf("%d", &num1_int);
                if (num1_int >= 0) {
                    long long factorial = 1; // Use long long for larger factorials
                    for (int i = 1; i <= num1_int; ++i) {
                        factorial *= i;
                    }
                    printf("Result = %lld\n", factorial);
                } else {
                    printf("Error: Factorial is only for non-negative integers.\n");
                }
                break;

            case 9: {
                int trig_choice;
                double angle_degrees, angle_radians;
                printf("\n  Trigonometry Menu:\n");
                printf("  1. Sine\n  2. Cosine\n  3. Tangent\n");
                printf("  Enter your trigonometry choice (1-3): ");
                scanf("%d", &trig_choice);
                printf("  Enter angle in degrees: ");
                scanf("%lf", &angle_degrees);

                // Convert degrees to radians for math.h functions
                angle_radians = angle_degrees * (PI / 180.0);

                if (trig_choice == 1) {
                    result = sin(angle_radians);
                    printf("  sin(%.2lf degrees) = %.4lf\n", angle_degrees, result);
                } else if (trig_choice == 2) {
                    result = cos(angle_radians);
                    printf("  cos(%.2lf degrees) = %.4lf\n", angle_degrees, result);
                } 
                else if (trig_choice == 3) 
                {
                    // Check for tangent of 90, 270 degrees etc.
                    if ((int)angle_degrees % 180 == 90 || (int)angle_degrees % 180 == -90) {
                        printf("  tan(%.2lf degrees) is undefined.\n", angle_degrees);
                    } 
                    else
                     {
                        result = tan(angle_radians);
                        printf("  tan(%.2lf degrees) = %.4lf\n", angle_degrees, result);
                    }
                } 
                else
                 {
                    printf("  Invalid trigonometry choice.\n");
                }
                break;
            }

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (1); // Loop indefinitely until "Exit" is chosen

    return 0;
}