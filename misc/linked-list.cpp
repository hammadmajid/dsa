#include <iostream>
#include "linked-list.h";

struct Song {
  std::string title;
  std::string album;
  std::string artist;
  u_int8_t runtime{};
};

Song generateSong() {
  Song s;
  return s;
}

void displaySong(const Song& s) {
  std::cout << "Title:   " << s.title << std::endl
    << "Artist:  " << s.artist << std::endl
    << "Album:   " << s.album << std::endl
    << "Runtime: " << s.runtime << std::endl;
}

int main() {
  LinkedList<Song> playlist;

  playlist.insert_at_head(generateSong());
  playlist.insert_at_tail(generateSong());
  playlist.insert_at_tail(generateSong());
  playlist.insert_at_tail(generateSong());
  playlist.insert_at_tail(generateSong());

  auto size = playlist.size();

  if (size != 5) {
    std::cout << "you messed up the size\n";
  }

  // for (int i = 0; i < size; i++) {
  //   displaySong(playlist.at(i));
  // }

  // playlist.removeLast();
  //
  // size = playlist.size();
  // for (int i = 0; i < size; i++) {
  //   displaySong(playlist.at(i));
  // }

  return 0;
}
