#ifndef OBJECT_H
# define OBJECT_H

# include <stdlib.h>
# include "libft/stdbool.h"
# include "matrix.h"
# include "model.h"
# include "camera.h"
# include "program.h"

typedef struct	s_object
{
	/* private attributes */
	struct s_object	*next;
	struct s_object	*prev;
	t_model			*model;

	/* public attributes */
	size_t		size; /* The size of the full struct including the
						 object member*/
	t_program	*program; /* ptr to the shader program (initialized or not) */
	char const	*model_path; /* Path of the .obj file*/
	t_transform	transform; /* standard transformations vectors
							  for the default draw */

	/* behavior hooks */
	void		(*init)(void *obj); /* post malloc -> memcpy hook
									   (before glinit)*/
	void		(*update)(void *obj); /* hook in the main loop */
}				t_object;

void	*objects_push(t_object const *obj); /*returns ptr to malloced(obj->size) */
void	objects_pop(t_object *obj);
void	objects_update(void); /* triggers all objects update() hooks */
void	objects_render(t_camera camera); /* renders all objects to screen */
void	objects_cleanup(void);

#endif