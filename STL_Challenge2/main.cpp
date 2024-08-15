// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating{};
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << std::endl << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for(const auto& song: playlist)
        std::cout << song << std::endl;

    std::cout << std::endl << "Current song: " << std::endl;
    std::cout << current_song << std::endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);

    char selection {};
    std::string name {}, artist {};
    int rating {0};

    do
    {
        display_menu();
        std::cin >> selection;

        switch (toupper(selection))
        {
            case 'F':
                std::cout << "Playing first song" << std::endl;
                current_song = playlist.begin();
                play_current_song(*current_song);
                break;
            case 'N':
                std::cout << "Playing next song" << std::endl;
                ++current_song;
                if(current_song == playlist.end())
                {
                    std::cout << "Wrapping to start of playlist" << std::endl;
                    current_song = playlist.begin();
                }
                play_current_song(*current_song);
                break;
            case 'P':
                std::cout << "Playing previous song" << std::endl;
                if(current_song == playlist.begin())
                {
                    std::cout << "Wrapping to end of playlist" << std::endl;
                    current_song = playlist.end();
                }
                --current_song;
                play_current_song(*current_song);
                break;
        case 'A':
                std::cin.clear();
                std::cout << "Adding and playing new song" << std::endl;
                std::cout << "Please type the name artist and rating of the song you want to add: ";
                std::cin >> name >> artist >> rating;

                playlist.emplace(current_song, name, artist, rating);
                --current_song;
                play_current_song(*current_song);
                break;
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            default:
                std::cout << "Not a valid selection, please try again." << std::endl;
        }
    } while(toupper(selection) != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}