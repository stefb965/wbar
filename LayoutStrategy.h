#ifndef _LAYOUTSTRATEGY_
#define _LAYOUTSTRATEGY_

#include <vector>
#include "Geometry.h"

class LayoutStrategy {
  public:
    virtual ~LayoutStrategy() = 0;

    virtual void unfocus() = 0;
    virtual void focus(const Point &p) = 0;

    virtual int widgetAt(const Point &x) const = 0;
    virtual bool atHoverZone(const Point &x) const = 0;

    virtual Size frameSize() const = 0;
};


class WaveLayout : public LayoutStrategy {
  public:

    WaveLayout(int num_widgets, int widget_size = 32,
               int num_anim = 5, float zoom_factor = 1.8,
               float jump_factor = 1.0);

    void unfocus();
    void focus(const Point &p);

    int widgetAt(const Point &x) const;
    bool atHoverZone(const Point &x) const;

    const Rect & widgetLayout(int idx) const;
    const Rect & dockLayout() const;

    Size frameSize() const;

  private:
    int widget_size;
    int widget_dist;
    int num_animated;
    float zoom_factor;
    float jump_factor;

    int widget_unit() const;
    //float scaled_unit() const;
    int side_num_anim() const;
    //int widget_offset() const;
    int widget_growth() const;

    int bar_x() const;
    int bar_y() const;
    int expanded_width() const;
    int bar_height() const;

    float _upgrowth() const;
    float _dngrowth() const;

    std::vector<Point> position;
    std::vector<Rect> bounds;
};


class CoverflowLayout : public LayoutStrategy {
};

#endif /* _LAYOUTSTRATEGY_ */

/* vim: set sw=2 sts=2 : */
