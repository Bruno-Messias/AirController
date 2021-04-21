#include <termios.h>
#include <unistd.h> 
    
class keyboard{
    public:
        keyboard();
        ~keyboard();
        int kbhit();
        int getch();
    private:
        struct termios initial_settings, new_settings;
        int peek_character;
};