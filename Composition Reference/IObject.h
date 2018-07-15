#pragma once

class IObject
  {
  public:
    IObject() {};
    virtual ~IObject() {};
  };

class IDrawable
  {
  public:
    virtual void Draw() = 0;
  };

class IDrawableObject
  {
  public:
    virtual IDrawable* GetDrawable() = 0;
  };

class UILineDrawer : public IDrawable
  {
  public:
    virtual void Draw() {};
  };

class UILine : public IObject, public IDrawableObject
  {
  public:
    UILine()
      : mp_drawable(new UILineDrawer)
      {
      }

    virtual IDrawable* GetDrawable() override
      {
      return mp_drawable;
      }

  private:
    IDrawable* mp_drawable;
  };

//////////////////////////////////////////////////////////////////////////

class PolygonDrawer : public IDrawable
  {
  public:
    virtual void Draw() {};
  };


class UIPolygon : public IObject, public IDrawableObject
  {
  public:
    UIPolygon()
      : mp_drawable(new PolygonDrawer)
      {
      }

    virtual IDrawable* GetDrawable() override
      {
      return mp_drawable;
      }

  private:
    IDrawable * mp_drawable;
  };

