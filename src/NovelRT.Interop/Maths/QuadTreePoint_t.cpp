// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.
#include "NovelRT.Interop/Maths/QuadTreePoint_t.h"
#include "NovelRT.h"
#include <list>

std::list<std::shared_ptr<NovelRT::Maths::QuadTreePoint>> _pointCollection; //TODO: Why a list? - Ruby

#ifdef __cplusplus
using namespace NovelRT;
extern "C" {
#endif

  QuadTreePoint_t QuadTreePoint_create(GeoVector2F_t& position) {
    auto pos = reinterpret_cast<Maths::GeoVector2<float>&>(position);
    auto point = std::make_shared<Maths::QuadTreePoint>(pos);
    _pointCollection.push_back(point);
    return reinterpret_cast<QuadTreePoint_t&>(point);
  }

  QuadTreePoint_t QuadTreePoint_createFromFloat(float x, float y) {
    auto point = std::make_shared<Maths::QuadTreePoint>(Maths::GeoVector2<float>(x, y));
    _pointCollection.push_back(point);
    return reinterpret_cast<QuadTreePoint_t&>(_pointCollection.back());
  }

  GeoVector2F_t QuadTreePoint_getPosition(QuadTreePoint_t point) {
    Maths::GeoVector2<float>* pos = new Maths::GeoVector2<float>();
    *pos = reinterpret_cast<std::shared_ptr<Maths::QuadTreePoint>&>(point)->getPosition();
    return reinterpret_cast<const GeoVector2F_t&>(*pos);
  }

  void QuadTreePoint_delete(QuadTreePoint_t point) {
    _pointCollection.remove(reinterpret_cast<std::shared_ptr<Maths::QuadTreePoint>&>(point));
  }



#ifdef __cplusplus

}
#endif
