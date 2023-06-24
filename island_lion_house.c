#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_ARTIST_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_ARTWORK_TITLE_LENGTH 100

/* Community art studio data structure */ 
struct ArtStudio {
	float cost;
	char artist[MAX_ARTIST_LENGTH];
	char category[MAX_CATEGORY_LENGTH];
	char artworkTitle[MAX_ARTWORK_TITLE_LENGTH];
};

/* Function Prototypes */
void printDetails(struct ArtStudio artStudio);
int isEmpty(struct ArtStudio artStudio);
int isInPriceRange(struct ArtStudio artStudio, float minPrice, float maxPrice);
int isByArtists(struct ArtStudio artStudio, char artist[]);
int isByCategory(struct ArtStudio artStudio, char category[]);

/*================ MAIN ================*/
int main(int argc, char* argv[]) {

	// Create a new artwork 
	struct ArtStudio artStudio1;
	artStudio1.cost = 20;
	strcpy(artStudio1.artist, "Adam Smith");
	strcpy(artStudio1.category, "Abstract Art");
	strcpy(artStudio1.artworkTitle, "A Trip to Paradise");

	// Create another artwork 
	struct ArtStudio artStudio2;
	artStudio2.cost = 30;
	strcpy(artStudio2.artist, "John Doe");
	strcpy(artStudio2.category, "Landscape Art");
	strcpy(artStudio2.artworkTitle, "Lakeside View");

	// Create an array of artwork objects 
	struct ArtStudio artStudioArray[10];
	artStudioArray[0] = artStudio1;
	artStudioArray[1] = artStudio2;
	
	// Print all the details of the artwork 
	printf("\nDetails of all the artwork in The Community Art Studio:\n");
	for (int i=0; i<10; i++) {
		if (!isEmpty(artStudioArray[i])) {
			printDetails(artStudioArray[i]);
		}
	}

	// Print all artwork with price in between $25 and $35
	printf("\nArtwork within price range of $25 and $35:\n");
	float minPrice = 25;
	float maxPrice = 35;
	for (int i=0; i<10; i++) {
		if (!isEmpty(artStudioArray[i]) && isInPriceRange(artStudioArray[i], minPrice, maxPrice)) {
			printDetails(artStudioArray[i]);
		}
	}

	// Print all artwork by John Doe
	printf("\nArtwork by John Doe:\n");
	char artist[] = "John Doe";
	for (int i=0; i<10; i++) {
		if (!isEmpty(artStudioArray[i]) && isByArtists(artStudioArray[i], artist)) {
			printDetails(artStudioArray[i]);
		}
	}

	// Print all Abstract Art work 
	printf("\nAbstract Artwork:\n");
	char category[] = "Abstract Art";
	for (int i=0; i<10; i++) {
		if (!isEmpty(artStudioArray[i]) && isByCategory(artStudioArray[i], category)) {
			printDetails(artStudioArray[i]);
		}
	}

	return 0;
}

// Function to print details of artwork 
void printDetails(struct ArtStudio artStudio) {
	printf("\nCost: %.2f\n", artStudio.cost);
	printf("Artist: %s\n", artStudio.artist);
	printf("Category: %s\n", artStudio.category);
	printf("Artwork Title: %s\n", artStudio.artworkTitle);
}

// Function to check if artwork is empty
int isEmpty(struct ArtStudio artStudio) {
	if (strlen(artStudio.artist) == 0) {
		return TRUE;
	}
	return FALSE;
}

// Function to check if the artwork is in the given price range
int isInPriceRange(struct ArtStudio artStudio, float minPrice, float maxPrice) {
	if (artStudio.cost >= minPrice && artStudio.cost <= maxPrice) {
		return TRUE;
	}
	return FALSE;
}

// Function to check if artwork is by a given artist
int isByArtists(struct ArtStudio artStudio, char artist[]) {
	if (strcmp(artStudio.artist, artist) == 0) {
		return TRUE;
	}
	return FALSE;
}

// Function to check if artwork is in a given category
int isByCategory(struct ArtStudio artStudio, char category[]) {
	if (strcmp(artStudio.category, category) == 0) {
		return TRUE;
	}
	return FALSE;
}