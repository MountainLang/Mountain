#pragma once
#include <stdint.h>



struct NODE *root_node;
struct NODE *current_parse_parent_node;



enum AST_TYPE {AST_ROOT, AST_DEF, AST_SET, AST_LITERAL};
enum LITERAL_TYPE {LITERAL_INT};

struct NODE
{
	enum AST_TYPE type;

	struct NODE *parent;
	struct NODE *next_node;
	struct NODE *first_child;
	struct NODE *last_child;

	char *type_name; //For def and get

	uint32_t stack_len;
	uint32_t def_location; //Where in the stack the var is if def or get

	char *variable_name; //def, var, get, and set name

	enum LITERAL_TYPE literal_type;
	char *literal_string;
};


struct NODE *create_node(enum AST_TYPE);


void add_node(struct NODE *parent, struct NODE *new_node);


void free_node(struct NODE *child);
