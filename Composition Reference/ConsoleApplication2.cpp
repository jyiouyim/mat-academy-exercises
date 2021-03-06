// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "IObject.h"

#include <string>
#include <iostream>
#include <vector>

//////////////////////////////////////////////////////////////////////////

int main()
  {
  std::vector<IObject*> all_objects;
  all_objects.push_back(new UILine());
  all_objects.push_back(new UIPolygon());

  for (auto& p_object : all_objects)
    {
    if (auto p_drawable = dynamic_cast<IDrawableObject*>(p_object))
      {
      auto p_drawer = p_drawable->GetDrawable();
      p_drawer->Draw();
      }
    }
  return 0;
  }
