#ifndef PARALLEL_YEE_GRID_LAYOUT_H
#define PARALLEL_YEE_GRID_LAYOUT_H

#include "YeeGridLayout.h"
#include "ParallelGridCore.h"

#ifdef PARALLEL_GRID

/**
 * Parallel Yee grid layout with size of grid per nodes
 */
class ParallelYeeGridLayout: public YeeGridLayout
{
private:

  ParallelGridCoordinate sizeForCurNode; /**< size of grid for current node */
  const ParallelGridCore *parallelGridCore; /**< parallel grid core */

private:

#if defined (PARALLEL_BUFFER_DIMENSION_1D_X) || defined (PARALLEL_BUFFER_DIMENSION_1D_Y) || defined (PARALLEL_BUFFER_DIMENSION_1D_Z)

  void CalculateGridSizeForNode (grid_coord &, grid_coord &, int, bool, grid_coord) const;

#endif /* PARALLEL_BUFFER_DIMENSION_1D_X || PARALLEL_BUFFER_DIMENSION_1D_Y || PARALLEL_BUFFER_DIMENSION_1D_Z */

#if defined (PARALLEL_BUFFER_DIMENSION_2D_XY) || defined (PARALLEL_BUFFER_DIMENSION_2D_YZ) || defined (PARALLEL_BUFFER_DIMENSION_2D_XZ)

  void CalculateGridSizeForNode (grid_coord &, grid_coord &, int, bool, grid_coord,
                                 grid_coord &, grid_coord &, int, bool, grid_coord) const;

#endif /* PARALLEL_BUFFER_DIMENSION_2D_XY || PARALLEL_BUFFER_DIMENSION_2D_YZ || PARALLEL_BUFFER_DIMENSION_2D_XZ */

#if defined (PARALLEL_BUFFER_DIMENSION_3D_XYZ)

  void CalculateGridSizeForNode (grid_coord &, grid_coord &, int, bool, grid_coord,
                                 grid_coord &, grid_coord &, int, bool, grid_coord,
                                 grid_coord &, grid_coord &, int, bool, grid_coord) const;

#endif /* PARALLEL_BUFFER_DIMENSION_3D_XYZ */

public:

  virtual ParallelGridCoordinate getEpsSizeForCurNode () const;
  virtual ParallelGridCoordinate getMuSizeForCurNode () const;

  virtual ParallelGridCoordinate getExSizeForCurNode () const;
  virtual ParallelGridCoordinate getEySizeForCurNode () const;
  virtual ParallelGridCoordinate getEzSizeForCurNode () const;
  virtual ParallelGridCoordinate getHxSizeForCurNode () const;
  virtual ParallelGridCoordinate getHySizeForCurNode () const;
  virtual ParallelGridCoordinate getHzSizeForCurNode () const;

  /**
   * Get size of grid for current node
   *
   * @return size of grid for current node
   */
  ParallelGridCoordinate getSizeForCurNode () const
  {
    return sizeForCurNode;
  } /* getSizeForCurNode */

  void Initialize (const ParallelGridCore *);

  /**
   * Constructor of Parallel Yee grid
   */
  ParallelYeeGridLayout (GridCoordinate3D coordSize,
                         GridCoordinate3D sizePML,
                         GridCoordinate3D sizeScatteredZone,
                         FPValue incidentWaveAngle1, /**< teta */
                         FPValue incidentWaveAngle2, /**< phi */
                         FPValue incidentWaveAngle3, /**< psi */
                         bool isDoubleMaterialPrecision)
    : YeeGridLayout (coordSize,
                     sizePML,
                     sizeScatteredZone,
                     incidentWaveAngle1,
                     incidentWaveAngle2,
                     incidentWaveAngle3,
                     isDoubleMaterialPrecision)
  {
  } /* ParallelYeeGridLayout */

  virtual ~ParallelYeeGridLayout ()
  {
  } /* ~ParallelYeeGridLayout */

#ifdef DYNAMIC_GRID
  bool Rebalance (time_step);
#endif /* DYNAMIC_GRID */
}; /* ParallelYeeGridLayout */

#endif /* PARALLEL_GRID */

#endif /* PARALLEL_YEE_GRID_LAYOUT_H */
