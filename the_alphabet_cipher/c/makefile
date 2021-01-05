.PHONY : all run clean unit

SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out
UTESTS_DIR := ./test

CC := gcc
CFLAGS := -std=gnu99 -I$(INC_DIR) -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wpedantic

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)
INCS := $(filter-out $(INC_DIR)/main.h, $(SRCS:$(SRC_DIR)/%.c=$(INC_DIR)/%.h))

U_CFLAGS := -lcheck -lpthread -lrt
U_SRCS := $(wildcard $(UTESTS_DIR)/*.c)
U_OBJS := $(U_SRCS:$(UTESTS_DIR)/%.c=$(OUT_DIR)/%.o)
U_OBJS += $(filter-out $(OUT_DIR)/main.o, $(OBJS))

EXEC := app.exe
UEXEC := unit_tests.exe

all: $(EXEC)

run: $(EXEC)
	./$^ $(args)

$(EXEC): $(OBJS) $(INCS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)

unit : $(UEXEC)
	@./$(UEXEC)

$(UEXEC) : $(U_OBJS) $(INCS)
	@$(CC) $(CFLAGS) -o $@ $(U_OBJS) $(U_CFLAGS)

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

${OUT_DIR}/%.o : ${SRC_DIR}/%.c $(OUT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%_check.o : $(UTESTS_DIR)/%_check.c $(OUT_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(INC_DIR)/%.h:

clean:
	@$(RM) $(EXEC) $(UEXEC) ${OUT_DIR}/*
	@rm -rf $(OUT_DIR)
