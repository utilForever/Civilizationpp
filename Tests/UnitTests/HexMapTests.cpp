#include <gtest/gtest.h>

#include <HexMap.h>
#include <HexTile.h>

using namespace Civilizationpp;

TEST(HexMap, ShouldAlwaysHaveOrigin)
{
    HexMap::GetInstance()->Generate(GameSettings(3, 3));

    HexTile* origin = HexMap::GetInstance()->GetTile(0, 0);
    ASSERT_NE(origin, static_cast<HexTile*>(nullptr));
}

TEST(HexMap, ShouldReturnNullptrForInvalidCoordinates)
{
    HexMap::GetInstance()->Generate(GameSettings(3, 3));

    HexTile* invalid = HexMap::GetInstance()->GetTile(-100, -100);
    ASSERT_EQ(invalid, static_cast<HexTile*>(nullptr));
}

TEST(HexMap, ShouldGenerateDefaultMapOnConstruction)
{
    HexMap::GetInstance()->Generate(GameSettings(3, 3));

    for (int r = -2; r <= 2; ++r)
    {
        for (int q = -2; q <= 2; ++q)
        {
            if (r == -2 || r == 2)
            {
                ASSERT_EQ(HexMap::GetInstance()->GetTile(r, q),
                          static_cast<HexTile*>(nullptr));
            }
            else
            {
                ASSERT_NE(HexMap::GetInstance()->GetTile(r, q),
                          static_cast<HexTile*>(nullptr));
            }
        }
    }
}

TEST(HexMap, ShouldSupportColumnWiseWraparound)
{
    HexMap::GetInstance()->Generate(GameSettings(3, 3));

    ASSERT_NE(HexMap::GetInstance()->GetTile(-1, -2),
              static_cast<HexTile*>(nullptr));
    ASSERT_NE(HexMap::GetInstance()->GetTile(0, -2),
              static_cast<HexTile*>(nullptr));
    ASSERT_NE(HexMap::GetInstance()->GetTile(+1, -2),
              static_cast<HexTile*>(nullptr));
    ASSERT_NE(HexMap::GetInstance()->GetTile(-1, +2),
              static_cast<HexTile*>(nullptr));
    ASSERT_NE(HexMap::GetInstance()->GetTile(0, +2),
              static_cast<HexTile*>(nullptr));
    ASSERT_NE(HexMap::GetInstance()->GetTile(1, +2),
              static_cast<HexTile*>(nullptr));
}

TEST(HexMap, ShouldNotSupportRowWiseWraparound)
{
    HexMap::GetInstance()->Generate(GameSettings(3, 3));

    ASSERT_EQ(HexMap::GetInstance()->GetTile(-2, -1),
              static_cast<HexTile*>(nullptr));
    ASSERT_EQ(HexMap::GetInstance()->GetTile(-2, 0),
              static_cast<HexTile*>(nullptr));
    ASSERT_EQ(HexMap::GetInstance()->GetTile(-2, +1),
              static_cast<HexTile*>(nullptr));
    ASSERT_EQ(HexMap::GetInstance()->GetTile(+2, -2),
              static_cast<HexTile*>(nullptr));
    ASSERT_EQ(HexMap::GetInstance()->GetTile(+2, -1),
              static_cast<HexTile*>(nullptr));
    ASSERT_EQ(HexMap::GetInstance()->GetTile(+2, 0),
              static_cast<HexTile*>(nullptr));
    ASSERT_EQ(HexMap::GetInstance()->GetTile(+2, +1),
              static_cast<HexTile*>(nullptr));
}

TEST(HexMap, ShouldReturnVectorOfNonNullptrAdjacentTilesOnRequest)
{
    HexMap::GetInstance()->Generate(GameSettings(3, 3));

    std::vector<HexTile*> adjacenciesToOrigin =
        HexMap::GetInstance()->GetAdjacencies(0, 0);
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(), adjacenciesToOrigin.end(),
                        HexMap::GetInstance()->GetTile(-1, 0)),
              adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(), adjacenciesToOrigin.end(),
                        HexMap::GetInstance()->GetTile(-1, 1)),
              adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(), adjacenciesToOrigin.end(),
                        HexMap::GetInstance()->GetTile(0, 1)),
              adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(), adjacenciesToOrigin.end(),
                        HexMap::GetInstance()->GetTile(1, 0)),
              adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(), adjacenciesToOrigin.end(),
                        HexMap::GetInstance()->GetTile(1, -1)),
              adjacenciesToOrigin.end());
    ASSERT_NE(std::find(adjacenciesToOrigin.begin(), adjacenciesToOrigin.end(),
                        HexMap::GetInstance()->GetTile(0, -1)),
              adjacenciesToOrigin.end());
    ASSERT_EQ(adjacenciesToOrigin.size(), (size_t)6);

    std::vector<HexTile*> adjacenciesToEdge =
        HexMap::GetInstance()->GetAdjacencies(-1, -1);
    ASSERT_NE(std::find(adjacenciesToEdge.begin(), adjacenciesToEdge.end(),
                        HexMap::GetInstance()->GetTile(-1, -2)),
              adjacenciesToEdge.end());
    ASSERT_NE(std::find(adjacenciesToEdge.begin(), adjacenciesToEdge.end(),
                        HexMap::GetInstance()->GetTile(0, -2)),
              adjacenciesToEdge.end());
    ASSERT_NE(std::find(adjacenciesToEdge.begin(), adjacenciesToEdge.end(),
                        HexMap::GetInstance()->GetTile(0, -1)),
              adjacenciesToEdge.end());
    ASSERT_NE(std::find(adjacenciesToEdge.begin(), adjacenciesToEdge.end(),
                        HexMap::GetInstance()->GetTile(-1, 0)),
              adjacenciesToEdge.end());
    ASSERT_EQ(adjacenciesToEdge.size(), (size_t)4);
}