
# Fichiers source
SOURCE = mlxtester.c julia.c zoom.c utils.c

# Objets
OBJET = $(SOURCE:.c=.o)

# Options de compilation (inclut le chemin pour les fichiers d'en-tête de MinilibX)
CFLAGS = -Wall -Werror -Wextra -Iminilibx

# Options de liaison (inclut le chemin pour la bibliothèque MinilibX)
LDFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

# Compilateur
CC = gcc

# Nom de l'exécutable
NAME = fractol

# Chemin vers MinilibX
MLX_PATH = minilibx

# Règle principale
all: $(MLX_PATH)/libmlx.a $(NAME)

# Compilation de l'exécutable avec MinilibX
$(NAME): $(OBJET)
	@$(CC) $(OBJET) $(LDFLAGS) -o $(NAME)

# Compilation de la bibliothèque MinilibX
$(MLX_PATH)/libmlx.a:
	@$(MAKE) -C $(MLX_PATH)

# Compilation des fichiers .c en .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Suppression des fichiers objets
clean:
	rm -f $(OBJET)
	$(MAKE) -C $(MLX_PATH) clean

# Suppression des fichiers objets et de l'exécutable
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all
