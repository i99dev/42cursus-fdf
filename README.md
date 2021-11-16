<img src="./image/minilibx.png">

# Minilibx - A minimalistic library for C programming
i'm design this to develop my project on 42 ABU DHABI CAMPUS in 2021 and i'm using it to develop my project on my own.

### Note:
there is two version for minilibx library:

[*] Linux: you cna use it on docker container.

[*] macos :this version you can get from inter patrol on project description.

**we are use Linux version.**
on make file here some differnt if your work under docker linux system.
compile the project will be like this:
```
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
```
```
$(NAME): $(OBJ)
	$(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
```
if there Object need put first ,like:
```
$(NAME): $(OBJ)
	$(CC) $(OBJ_DIR) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
```

### Compilation on macOS:
Because MiniLibX requires AppKit and X11 we need to link them accordingly. This can cause a complicated compilation process. A basic compilation process looks as follows:

For object files, you could add the following rule to your makefile, assuming that you have the mlx source in a directory named mlx in the root of your project:

```
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
```
To link with the required internal macOS API:

```
$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
```
Do mind that you need the libmlx.dylib in the same directory as your build target as it is a dynamic library!
### MACOS user.
- download X11 on you mac and keep it open when are you use 

### windows or Lunix user.
 - i use this docker under windoes 10 and work for me for perfect but you need to  do this one 