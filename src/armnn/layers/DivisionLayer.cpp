//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "DivisionLayer.hpp"

#include "LayerCloneBase.hpp"

#include <armnn/TypesUtils.hpp>
#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

namespace armnn
{

DivisionLayer::DivisionLayer(const char* name)
    : ElementwiseBaseLayer(2, 1, LayerType::Division, name)
{
}

std::unique_ptr<IWorkload> DivisionLayer::CreateWorkload(const Graph& graph,
                                                         const IWorkloadFactory& factory) const
{
    DivisionQueueDescriptor descriptor;
    return factory.CreateDivision(descriptor, PrepInfoAndDesc(descriptor, graph));
}

DivisionLayer* DivisionLayer::Clone(Graph& graph) const
{
    return CloneBase<DivisionLayer>(graph, GetName());
}

void DivisionLayer::Accept(ILayerVisitor& visitor) const
{
    visitor.VisitDivisionLayer(this, GetName());
}

} // namespace armnn
