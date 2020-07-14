# PI-Day-2016-BPAC
One of my first C++ console applications. Won best program at my high school's 2016 PI day contest. 

## Background
The Basic PI application console (BPAC) was one of my first C++ applications. It was developed over the course of 3 days in early 2016 for my school's PI day contest. The project drew inspiration from other custom command lines, and really just ended up being a fun project for me to design my own command line with. It was my first project using arrays in C++, but as I didn't know about dynamic memory / vectors yet, I ended up using a fixed size array. 

The project ended up having support for three levels of user privileges (Guest, User, Admin) pretending to be its own faux command line OS. Each privilege level had a set of commands it was allowed to run, some of these being "OS features" like creating new users, while others were "Programs" which were just void functions hard coded into the main program. 

## Screenshots
### Splash Screen
![splash screen](https://raw.githubusercontent.com/James-Oswald/PI-Day-2016-BPAC/master/screenshots/opening.png)
### Admin List
A list of all commands on the system obtained by running the `List` command in admin mode  
![Admin List](https://raw.githubusercontent.com/James-Oswald/PI-Day-2016-BPAC/master/screenshots/admin.png)
