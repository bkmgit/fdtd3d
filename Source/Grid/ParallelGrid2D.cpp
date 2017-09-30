#include "ParallelGrid.h"

#ifdef GRID_2D

#ifdef PARALLEL_GRID

#if defined (PARALLEL_BUFFER_DIMENSION_1D_X) || defined (PARALLEL_BUFFER_DIMENSION_1D_Y)

/**
 * Initialize 2D grid of computational nodes
 */
void
ParallelGridCore::NodeGridInit (ParallelGridCoordinate size) /**< size of grid */
{
#ifdef PARALLEL_BUFFER_DIMENSION_1D_X
  if (!doUseManualTopology)
  {
    nodeGridSizeX = totalProcCount;
  }
  else
  {
    nodeGridSizeX = topologySize.getX ();
  }
  nodeGridSizeY = 1;

  if (nodeGridSizeX <= 1)
  {
    ASSERT_MESSAGE ("2D-X virtual topology could be used only with number of processes > 1 by Ox axis. "
                    "Use without parallel grid");
  }
#endif /* PARALLEL_BUFFER_DIMENSION_1D_X */

#ifdef PARALLEL_BUFFER_DIMENSION_1D_Y
  if (!doUseManualTopology)
  {
    nodeGridSizeY = totalProcCount;
  }
  else
  {
    nodeGridSizeY = topologySize.getY ();
  }
  nodeGridSizeX = 1;

  if (nodeGridSizeY <= 1)
  {
    ASSERT_MESSAGE ("2D-Y virtual topology could be used only with number of processes > 1 by Oy axis. "
                    "Use without parallel grid");
  }
#endif /* PARALLEL_BUFFER_DIMENSION_1D_Y */

  if (getProcessId () == 0)
  {
    printf ("Nodes' grid (%s): %dx%d.\n",
            doUseManualTopology ? "manual" : "optimal",
            nodeGridSizeX,
            nodeGridSizeY);
  }
} /* ParallelGridCore::NodeGridInit */

#endif /* PARALLEL_BUFFER_DIMENSION_1D_X || PARALLEL_BUFFER_DIMENSION_1D_Y */

#ifdef PARALLEL_BUFFER_DIMENSION_2D_XY

/**
 * Initialize 2D grid of computational nodes
 */
void
ParallelGridCore::NodeGridInit (ParallelGridCoordinate size) /**< size of grid */
{
  if (totalProcCount < 4)
  {
    ASSERT_MESSAGE ("Unsupported number of nodes for 2D parallel buffers. Use 1D ones.");
  }

  if (!doUseManualTopology)
  {
    initOptimal (size.getX (), size.getY (), nodeGridSizeX, nodeGridSizeY);
  }
  else
  {
    nodeGridSizeX = topologySize.getX ();
    nodeGridSizeY = topologySize.getY ();
  }

  nodeGridSizeXY = nodeGridSizeX * nodeGridSizeY;

  if (nodeGridSizeX <= 1 || nodeGridSizeY <= 1)
  {
    ASSERT_MESSAGE ("2D-XY virtual topology could be used only with number of processes > 1 by Ox and Oy axis. "
                    "Recompile with `-DPARALLEL_BUFFER_DIMENSION=x`, or `-DPARALLEL_BUFFER_DIMENSION=y`, or "
                    "use without parallel grid");
  }

  if (getProcessId () == 0)
  {
    printf ("Nodes' grid (%s): %dx%d.\n",
            doUseManualTopology ? "manual" : "optimal",
            nodeGridSizeX,
            nodeGridSizeY);
  }
} /* ParallelGridCore::NodeGridInit */

#endif /* PARALLEL_BUFFER_DIMENSION_2D_XY */

#endif /* PARALLEL_GRID */

#endif /* GRID_2D */
