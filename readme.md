# Book Comparison Project

## Overview

This project aims to analyze and compare 64 books using text analysis techniques. The main objectives are:

1. Identify the 100 most frequently used words across all books.
2. Create a 64x64 similarity matrix comparing all books based on these words.
3. Determine the top 10 most similar book pairs.

## Dataset

The dataset consists of 64 books in TXT document format. Each book is processed to extract its textual content for analysis.

## Methodology

### 1. Word Frequency Analysis

- Preprocess the text data (remove punctuation, convert to lowercase, etc.)
- Count word occurrences across all books
- Identify the top 100 most frequently used words

### 2. Book Comparison

- Create feature vectors for each book based on the top 100 words
- Compute similarity scores between all pairs of books (64x64 matrix)
- Use cosine similarity or another appropriate metric for comparison

### 3. Similarity Ranking

- Sort the similarity scores to identify the top 10 most similar book pairs

## Implementation

The project is implemented in C++, utilizing the following components:

- `Book` class: Represents individual books and their properties
- `Library` class: Manages the collection of books and comparison operations
- Text processing functions for word extraction and counting
- Similarity calculation algorithms

## Results

The program outputs:

1. List of the top 100 most frequently used words across all books
2. 64x64 similarity matrix
3. Top 10 most similar book pairs with their similarity scores

## Future Enhancements

- Implement more advanced text processing techniques (e.g., stemming, lemmatization)
- Explore alternative similarity metrics
- Visualize the similarity matrix and book relationships
- Extend the analysis to include sentiment or topic modeling

## Usage

Instructions on how to run the program and any dependencies will be provided here.

## Contributors

List of project contributors and their roles.

## License

Specify the license under which this project is released.
