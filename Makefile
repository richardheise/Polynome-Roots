CC = gcc -g

CFLAGS = -I./src
LFLAGS = -lm

PROG = laboratorioZero
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Encontra todos os arquivos .c no diretório de origem
SRCS = $(wildcard $(SRCDIR)/*.c)
# Gera os nomes dos arquivos objeto a partir dos nomes dos arquivos de origem
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# O alvo padrão é 'all'
all: $(BINDIR)/$(PROG)

# Regra para lincar o programa principal
$(BINDIR)/$(PROG): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

# Regra para compilar os arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Alvos phony (não são nomes de arquivos)
.PHONY: clean purge

# Remove todos os arquivos gerados
clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJDIR) $(BINDIR)

# Alias para 'clean'
purge: clean

# Phony para o alvo 'all'
.PHONY: all
