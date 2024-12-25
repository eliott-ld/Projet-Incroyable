#include "text_box.hh"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Function to calculate the display width of a string (UTF-8 aware)
size_t getDisplayWidth(const std::string &line) {
  size_t width = 0;
  for (size_t i = 0; i < line.length();) {
    unsigned char ch = line[i];
    size_t charLen;

    // Determine the number of bytes in the current character
    if ((ch & 0x80) == 0) {
      charLen = 1; // 1-byte ASCII
      width += 1;  // Single-width
    } else if ((ch & 0xE0) == 0xC0) {
      charLen = 2; // 2-byte UTF-8
      width += 1;  // Single-width
    } else if ((ch & 0xF0) == 0xE0) {
      charLen = 3; // 3-byte UTF-8
      width += 1;  // Single-width
    } else if ((ch & 0xF8) == 0xF0) {
      charLen = 4; // 4-byte UTF-8
      width += 2;  // Double-width (e.g., emoji, CJK)
    } else {
      throw std::runtime_error("Invalid UTF-8 encoding detected");
    }

    i += charLen; // Move to the next character
  }
  return width;
}

void printBoxedText(const std::string &text, const std::string &color) {
  std::size_t padding_x = 6;
  std::size_t padding_y = 3;
  std::size_t margin_x = 2;
  std::size_t margin_y = 1;

  std::cout << color;

  // Split the text into lines
  std::vector<std::string> lines;
  std::istringstream stream(text);
  std::string line;
  size_t maxLength = 0;

  while (std::getline(stream, line)) {
    lines.push_back(line);
    size_t displayWidth = getDisplayWidth(line);
    if (displayWidth > maxLength) {
      maxLength = displayWidth;
    }
  }

  // Determine the box width (including padding)
  size_t boxWidth = maxLength + 4 + padding_x;

  for (std::size_t i = 0; i < margin_y; i++) {
    std::cout << std::endl;
  }
  std::string floor_ceil = "";
  for (std::size_t i = 0; i < boxWidth - 2; i++) {
    floor_ceil += "─";
  }

  for (std::size_t i = 0; i < margin_x; i++) {
    std::cout << " ";
  }
  // Print the top border
  std::cout << "╭" << floor_ceil << "╮" << std::endl;

  for (std::size_t i = 0; i < padding_y; i++) {
    for (std::size_t i = 0; i < margin_x; i++) {
      std::cout << " ";
    }
    std::cout << "│ " << std::string((maxLength + padding_x), ' ') << " │"
              << std::endl;
  }

  // Print each line of text
  for (const auto &l : lines) {
    for (std::size_t i = 0; i < margin_x; i++) {
      std::cout << " ";
    }
    size_t displayWidth = getDisplayWidth(l);
    auto a = maxLength - displayWidth + padding_x;
    for (auto c : l) {
      if (c == '\e')
        a += 6;
    }
    std::cout << "│ " << std::string(a / 2, ' ') << l;
    for (auto c : l) {
      if (c == '\e')
        a += 1;
    }

    if (a % 2 == 1)
      a++;
    // Add padding spaces if the line is shorter than the maximum length
    std::cout << std::string(a / 2, ' ') << " │" << std::endl;
  }
  for (std::size_t i = 0; i < padding_y; i++) {
    for (std::size_t i = 0; i < margin_x; i++) {
      std::cout << " ";
    }
    std::cout << "│ " << std::string((maxLength + padding_x), ' ') << " │"
              << std::endl;
  }

  for (std::size_t i = 0; i < margin_x; i++) {
    std::cout << " ";
  }
  // Print the bottom border
  std::cout << "╰" << floor_ceil << "╯" << std::endl;
  for (std::size_t i = 0; i < margin_y; i++) {
    std::cout << std::endl;
  }
  std::cout << "\e[0m";
}
