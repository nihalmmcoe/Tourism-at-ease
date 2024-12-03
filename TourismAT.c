#include <stdio.h>
#include <string.h>

#define MAX 5

// Structure to store tourist place data
struct TouristPlace
{
    char name[50];
    int visitorsPerDay;
    float fees;
    int avgAgeGroup; // Age group as an integer (e.g., 25 for 20-30 years)
};

// Function to sort tourist places by visitors per day (famous places)
void sortByVisitors(struct TouristPlace places[], int n)
{
    struct TouristPlace temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (places[i].visitorsPerDay < places[j].visitorsPerDay)
            {
                temp = places[i];
                places[i] = places[j];
                places[j] = temp;
            }
        }
    }
}

// Function to sort tourist places by fees (expensive places)
void sortByFees(struct TouristPlace places[], int n)
{
    struct TouristPlace temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (places[i].fees < places[j].fees)
            {
                temp = places[i];
                places[i] = places[j];
                places[j] = temp;
            }
        }
    }
}

// Function to sort tourist places by average age group of visitors (age preference)
void sortByAgeGroup(struct TouristPlace places[], int n)
{
    struct TouristPlace temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (places[i].avgAgeGroup > places[j].avgAgeGroup)
            {
                temp = places[i];
                places[i] = places[j];
                places[j] = temp;
            }
        }
    }
}

// Function to display the list of tourist places
void displayPlaces(struct TouristPlace places[], int n)
{
    printf("\n%-30s%-20s%-10s%-15s\n", "Tourist Place", "Visitors/Day", "Fees", "Avg Age Group");
    for (int i = 0; i < n; i++)
    {
        printf("%-30s%-20d%-10.2f%-15d\n", places[i].name, places[i].visitorsPerDay, places[i].fees, places[i].avgAgeGroup);
    }
}

int main()
{
    struct TouristPlace places[MAX];

    // Input tourist place data
    for (int i = 0; i < MAX; i++)
    {
        printf("\nEnter details for Tourist Place %d\n", i + 1);
        printf("Name: ");
        getchar(); // To clear the buffer before taking string input
        fgets(places[i].name, sizeof(places[i].name), stdin);
        places[i].name[strcspn(places[i].name, "\n")] = 0; // Remove trailing newline
        printf("Visitors per day: ");
        scanf("%d", &places[i].visitorsPerDay);
        printf("Fees: ");
        scanf("%f", &places[i].fees);
        printf("Average age group (e.g., 25 for 20-30 years): ");
        scanf("%d", &places[i].avgAgeGroup);
    }

    // Sorting and displaying famous places (sorted by visitors per day)
    sortByVisitors(places, MAX);
    printf("\n--- Tourist Places Sorted by Famous (Visitors per Day) ---");
    displayPlaces(places, MAX);

    // Sorting and displaying expensive places (sorted by fees)
    sortByFees(places, MAX);
    printf("\n--- Tourist Places Sorted by Expensive (Fees) ---");
    displayPlaces(places, MAX);

    // Sorting and displaying places based on age group (sorted by average age group)
    sortByAgeGroup(places, MAX);
    printf("\n--- Tourist Places Sorted by Age Group Preference ---");
    displayPlaces(places, MAX);

    return 0;
}