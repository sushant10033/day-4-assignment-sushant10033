Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:
Input: s = "leetcode"
Output: 0
  def firstUniqChar(s: str) -> int:
    """
    Find the first non-repeating character in the string s and return its index.
    If it does not exist, return -1.

    :param s: Input string
    :return: Index of the first non-repeating character or -1 if none exists
    """
    # Use a dictionary to store the frequency of each character
    char_count = {}

    # Count the occurrences of each character
    for char in s:
        char_count[char] = char_count.get(char, 0) + 1

    # Find the first character with a count of 1
    for index, char in enumerate(s):
        if char_count[char] == 1:
            return index

    # If no unique character is found, return -1
    return -1

# Example usage:
# s = "leetcode"
# print(firstUniqChar(s))  # Output: 0
