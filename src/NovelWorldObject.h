// Copyright © Matt Jones and Contributors. Licensed under the MIT License (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_NOVELWORLDOBJECT_H
#define NOVELRT_NOVELWORLDOBJECT_H
#include "GeoVector.h"
#include "NovelCommonArgs.h"
#include "NovelLayeringService.h"
#include "GeoBounds.h"

namespace NovelRT {
class NovelLayeringService;
class NovelWorldObject {
public:
  NovelWorldObject(NovelLayeringService* layeringService, const GeoVector<float>& size,
                   const NovelCommonArgs& args);

  virtual ~NovelWorldObject();

  virtual GeoVector<float> getPosition() const;

  virtual void setPosition(const GeoVector<float>& value);

  virtual float getRotation() const;

  virtual void setRotation(float value);

  virtual GeoVector<float> getScale() const;

  virtual void setScale(const GeoVector<float>& value);

  virtual GeoVector<float> getSize() const;

  virtual void setSize(const GeoVector<float>& value);

  virtual int getLayer() const;

  virtual void setLayer(int value);

  virtual int getOrderInLayer() const;

  virtual void setOrderInLayer(int value);

  virtual bool getActive() const;

  virtual void setActive(bool value);

  virtual void executeObjectBehaviour() = 0;

protected:
  GeoVector<float> _position;
  GeoVector<float> _scale;
  GeoVector<float> _size;
  float _rotation;
  bool _active = true;
  int _orderInLayer;
  int _layer;
  NovelLayeringService* _layeringService;
};

}

#endif //NOVELRT_NOVELWORLDOBJECT_H