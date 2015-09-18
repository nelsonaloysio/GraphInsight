/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#include "EntityAttribute.h"
#include <stdlib.h>
/**
 * @brief EntityAttribute::EntityAttribute
 */
EntityAttribute::EntityAttribute() : type(EntityAttribute::TypeString), toStringReady(true), valueString("emptyEntity")
{
}

/**
 * @brief EntityAttribute::~EntityAttribute
 */
EntityAttribute::~EntityAttribute()
{
    //DEBUG_PRINT(("EntityAttribute destructor attribute=\""+this->valueString+"\""));
}

