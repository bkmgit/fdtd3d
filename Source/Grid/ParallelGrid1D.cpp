#include "ParallelGrid.h"

#ifdef GRID_1D

#ifdef PARALLEL_GRID

#ifdef PARALLEL_BUFFER_DIMENSION_1D_X

/**
 * Initialize 1D grid of computational nodes
 */
void
ParallelGridCore::NodeGridInit (ParallelGridCoordinate size) /**< size of grid */
{
  if (!doUseManualTopology)
  {
    nodeGridSizeX = totalProcCount;
  }
  else
  {
    nodeGridSizeX = topologySize.getX ();
  }

  if (nodeGridSizeX <= 1)
  {
    ASSERT_MESSAGE ("1D-X virtual topology could be used only with number of processes > 1 by Ox axis. "
                    "Use without parallel grid");
  }

  if (getProcessId () == 0)
  {
    printf ("Nodes' grid (%s): %d.\n",
            doUseManualTopology ? "manual" : "optimal",
            nodeGridSizeX);
  }
} /* ParallelGridCore::NodeGridInit */

#endif /* PARALLEL_BUFFER_DIMENSION_1D_X */

#endif /* PARALLEL_GRID */

#endif /* GRID_1D */
