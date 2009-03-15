/** \file settings.h Copyright (c) 2008 by Ben Klemens.  Licensed under the modified GNU GPL v2; see COPYING and COPYING2.  */
#ifndef __apop_settings_h__
#define __apop_settings_h__

#include "types.h"
#include "asst.h"

#undef __BEGIN_DECLS    /* extern "C" stuff cut 'n' pasted from the GSL. */
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

void * apop_settings_get_group(apop_model *m, char *type);
void apop_settings_rm_group(apop_model *m, char *delme);
void apop_settings_copy_group(apop_model *outm, apop_model *inm, char *copyme);
void apop_settings_group_alloc(apop_model *model, char *type, void *free_fn, void *copy_fn, void *the_group);

__END_DECLS

/** Retrieves a settings group from a model.  See \ref Apop_settings_get
 to just pull a single item from within the settings group.*/
#define Apop_settings_get_group(m, type) apop_settings_get_group(m, #type)

/** Removes a settings group from a model's list. */
#define Apop_settings_rm_group(m, type) apop_settings_rm_group(m, #type)

/* If the group already exists, it is silently removed. */

/** Add a settings group. You will need to provide arguments for the
 specific settings group you are dealing with, such as \ref apop_mle_settings_alloc, \ref apop_ls_settings_alloc, \ref apop_histogram_settings_alloc. */
#define Apop_settings_add_group(model, type, ...)  \
    apop_settings_group_alloc(model, #type, type ## _settings_free, type ## _settings_copy, type ##_settings_alloc (__VA_ARGS__)); 

/** Call \ref Apop_settings_add_group and \ref Apop_settings_add in sequence. */
#define Apop_settings_alloc_add(model, type, setting, data, ...)  \
    do {                                                \
        Apop_settings_add_group(model, type, __VA_ARGS__)           \
        Apop_settings_add(model, type, setting, data)       \
    } while (0);

/** Retrieves a setting from a model.  See \ref Apop_settings_get_group pull the entire group.*/
#define Apop_settings_get(model, type, setting)  \
    (((type ## _settings *) apop_settings_get_group(model, #type))->setting)

/** Modifies a single element of a settings group to the given value. */
#define Apop_settings_add(model, type, setting, data)  \
    do {                                                \
    apop_assert_void(apop_settings_get_group(model, #type), 0, 's', "You're trying to modify a setting in " \
                        #model "'s setting group of type " #type " but that model doesn't have such a group."); \
    ((type ## _settings *) apop_settings_get_group(model, #type))->setting = (data);    \
    } while (0);

#define APOP_SETTINGS_ADD Apop_settings_add
#define APOP_SETTINGS_ALLOC_ADD Apop_settings_alloc_add
#define APOP_SETTINGS_GET Apop_settings_get
#define APOP_SETTINGS_ADD_GROUP Apop_settings_add_group
#define APOP_SETTINGS_GET_GROUP Apop_settings_get_group
#define APOP_SETTINGS_RM_GROUP Apop_settings_rm_group

#endif