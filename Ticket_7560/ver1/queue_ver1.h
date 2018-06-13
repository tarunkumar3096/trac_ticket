#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef union g_datatype
{
     char char_g;
     short short_g;
     int int_g;
     long long_g;
     float float_g;
     double double_g;
} g_datatype;

enum g_typename
{
     CHAR,
     SHORT,
     INT,
     LONG,
     FLOAT,
     DOUBLE
};

struct element {
     g_datatype field;
     enum g_typename field_type;
};

struct vector_node {
     struct element element;
     struct vector_node *next;
     struct vector_node *prev;       
};

struct vector {
     struct vector_node *head;
     struct vector_node *tail;

     int (*append)(struct vector *vector, struct element element); /* V1 */
     int (*prepend)(struct vector *vector, struct element element);/* V1 */
     int (*insert)(struct vector *vector, int pos, struct element element);/* V1 */
     
     int (*chop)(struct vector *vector); /* V1 */
     int (*behead)(struct vector *vector); /* V1 */
     int (*delete)(struct vector *vector, int pos); /* V1 */
     
     int (*set)(struct vector *vector, int pos, struct element element); /* V1 */

     int (*get)(struct vector *vector, int pos, struct element *element); /* V1 */

     int (*is_empty)(struct vector *vector);

     int (*first)(struct vector *vector, struct element *element); /* V2 */
     int (*last)(struct vector *vector, struct element *element); /* V2 */
     int (*clear)(struct vector *vector); /* V2 */
     int (*destruct)(struct vector *vector); /* V2 */
     int (*size)(struct vector *vector); /* V2 */
     int (*move)(struct vector *vector, int old_pos, int new_pos); /* V2 */
     struct vector * (*splice)(struct vector *vector, int pos); /* V2 */
};

#define ELEMENT(data, type) \
     (struct element) { .field.long_g = data, .field_type = type}

#define for_each(entry, vector)                      \
    for(struct vector_node * entry = vector->head;\
      entry != NULL; entry = entry->next)

#define for_each_rev(entry, vector)                  \
    for(struct vector_node * entry = vector->tail;\
     entry != NULL; entry = entry->prev)       

#define VALUE(entry)  entry->element.field
#define TYPE(entry)   entry->element.field_type

/* # Public APIs # */
struct vector vector(struct vector *vector);

/* # Internal APIs # */

int append(struct vector *vector, struct element element);
int prepend(struct vector *vector, struct element element);
int insert(struct vector *vector, int pos, struct element element);

int chop(struct vector *vector);
int behead(struct vector *vector);
int delete(struct vector *vector, int pos);

/* Removes all the elements, but vector is available for other operations */ 
int clear(struct vector *vector);

/* Frees the complete vector useful only when dynamically allocated */
int destruct(struct vector *vector);

int move(struct vector *vector, int old_pos, int new_pos);

int set(struct vector *vector, int pos, struct element element);

/* Gives the element value but doesn't alter the list */
int first(struct vector *vector, struct element *element);
int last(struct vector *vector, struct element *element);
int get(struct vector *vector, int pos, struct element *element);

int is_empty(struct vector *vector);
int size(struct vector *vector);

/* Splices the vector into two and returns second vector which starts from the `pos`.*/
struct vector * splice(struct vector *vector, int pos);

#endif /* __VECTOR_H__ */
