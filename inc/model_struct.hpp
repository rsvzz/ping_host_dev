#pragma once

#include "glib-object.h"

#define PING_TYPE_ITEM ping_item_get_type()
G_DECLARE_FINAL_TYPE(PingItem, ping_item, PING, ITEM, GObject)


struct _PingItem
{
    GObject parent;
    int id;
    const char *value;
};

struct _PingItemClass {
    GObjectClass parent_class;
};

G_DEFINE_TYPE (PingItem, ping_item, G_TYPE_OBJECT)

static void ping_item_init(PingItem *item)
{
}

static void ping_item_class_init(PingItemClass *klass)
{
}

PingItem *ping_item_new(int id,const char *value)
{
    PingItem  *item = (PingItem*)g_object_new(PING_TYPE_ITEM, NULL);
    item->id = id;
    item->value = g_strdup(value);
    return item;
}
