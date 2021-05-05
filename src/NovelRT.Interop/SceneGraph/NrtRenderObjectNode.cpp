// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root
// for more information.

#include <NovelRT.Interop/NrtErrorHandling.h>
#include <NovelRT.Interop/SceneGraph/NrtRenderObjectNode.h>
#include <NovelRT.h>

#include <list>

using namespace NovelRT;

std::list<std::shared_ptr<Graphics::RenderObject>> _renderObjectNodeCollection;

#ifdef __cplusplus
extern "C"
{
#endif

    NrtResult Nrt_RenderObjectNode_create(NrtRenderObjectHandle object, NrtRenderObjectNodeHandle* outputNode)
    {
        if (object == nullptr || outputNode == nullptr)
        {
            Nrt_setErrMsgIsNullptrInternal();
            return NRT_FAILURE_NULL_ARGUMENT_PROVIDED;
        }

        auto ptr = reinterpret_cast<Graphics::RenderObject*>(object);
        std::shared_ptr<Graphics::RenderObject> cppObject = std::shared_ptr<Graphics::RenderObject>(ptr);
        _renderObjectNodeCollection.push_back(cppObject);
        *outputNode = reinterpret_cast<NrtRenderObjectNodeHandle>(new SceneGraph::RenderObjectNode(cppObject));
        return NRT_SUCCESS;
    }

    NrtResult Nrt_RenderObjectNode_getRenderObject(NrtRenderObjectNodeHandle node, NrtRenderObjectHandle* outputObject)
    {
        if (node == nullptr || outputObject == nullptr)
        {
            Nrt_setErrMsgIsNullptrInternal();
            return NRT_FAILURE_NULL_ARGUMENT_PROVIDED;
        }

        SceneGraph::RenderObjectNode* cppNode = reinterpret_cast<SceneGraph::RenderObjectNode*>(node);
        auto obj = cppNode->getRenderObject();
        *outputObject = reinterpret_cast<NrtRenderObjectHandle>(&obj);
        return NRT_SUCCESS;
    }

    NrtResult Nrt_RenderObjectNode_delete(NrtRenderObjectNodeHandle node)
    {
        if (node == nullptr)
        {
            Nrt_setErrMsgIsNullptrInternal();
            return NRT_FAILURE_NULL_ARGUMENT_PROVIDED;
        }

        auto cppNode = reinterpret_cast<SceneGraph::RenderObjectNode*>(node)->getRenderObject();
        for (auto innerNode : _renderObjectNodeCollection)
        {
            if (innerNode == cppNode)
            {
                _renderObjectNodeCollection.remove(innerNode);
                return NRT_SUCCESS;
            }
        }

        Nrt_setErrMsgIsAlreadyDeletedOrRemovedInternal();
        return NRT_FAILURE_ALREADY_DELETED_OR_REMOVED;
    }

#ifdef __cplusplus
}
#endif
