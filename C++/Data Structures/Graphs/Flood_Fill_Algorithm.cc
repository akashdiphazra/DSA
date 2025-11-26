#include <iostream>
#include <vector>

class Solution {
 public:
  void floodFillDFS(std::vector<std::vector<int>>& image, int x, int y,
                    int targetColor, int newColor) {
    int rows = image.size();
    int cols = image[0].size();

    // Base case: If out of bounds, or the color is not the targetColor, or
    // already filled with newColor
    if (x < 0 || x >= rows || y < 0 || y >= cols ||
        image[x][y] != targetColor || image[x][y] == newColor) {
      return;
    }

    // Fill the current cell with the new color
    image[x][y] = newColor;

    // Explore all four directions (up, down, left, right)
    floodFillDFS(image, x + 1, y, targetColor, newColor);  // Down
    floodFillDFS(image, x - 1, y, targetColor, newColor);  // Up
    floodFillDFS(image, x, y + 1, targetColor, newColor);  // Right
    floodFillDFS(image, x, y - 1, targetColor, newColor);  // Left
  }

  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
                                          int sr, int sc, int newColor) {
    int targetColor = image[sr][sc];  // Color at the starting point
    if (targetColor != newColor) {    // If the target color is not the same as
                                      // newColor, perform flood fill
      floodFillDFS(image, sr, sc, targetColor, newColor);
    }
    return image;
  }
};

int main() {
  Solution solution;
  std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  int sr = 1, sc = 1, newColor = 2;

  std::vector<std::vector<int>> result =
      solution.floodFill(image, sr, sc, newColor);

  // Print the result
  for (const auto& row : result) {
    for (int val : row) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
