#pragma once

#include "qmath.h"
#include <cstdint>
#include "remap.h"

void                        LoadR1BSPFile(const char* filename);
void                        WriteR1BSPFile(const char* filename);
void						CompileR1BSPFile();


namespace Titanfall {
	void EmitTextureData( shaderInfo_t shader );
	uint32_t EmitVertex( Vector3 &vertex );
	uint32_t EmitVertexNormal( Vector3 &normal );
	void EmitEntityPartitions();
	void EmitMeshes( const entity_t &e );
	uint16_t EmitMaterialSort( const char* texture );

	// 0x02
	struct TextureData_t {
		Vector3 reflectivity;
		uint32_t name_index;
		uint32_t sizeX;
		uint32_t sizeY;
		uint32_t visibleX;
		uint32_t visibleY;
		uint32_t flags;
	};

	// 0x0F
	struct Model_t {
		MinMax minmax;
		uint32_t firstMesh;
		uint32_t meshCount;
	};

	// 0x49
	struct VertexLitBump_t {
		uint32_t vertexIndex;
		uint32_t normalIndex;
		Vector2 uv0;
		int32_t negativeOne;
		Vector2 uv1;
		uint32_t unk[4];
	};

	// 0x50
	struct Mesh_t {
		uint32_t triOffset;
		uint16_t triCount;
		uint16_t firstVertex;
		uint16_t vertexCount;
		uint16_t unk0;
		uint32_t const0;
		uint16_t unk1;
		uint16_t unk2;
		uint16_t unk3;
		uint16_t materialOffset;
		uint32_t flags;
	};

	// 0x51
	struct MeshBounds_t {
		Vector3 origin;
		uint32_t unk0;
		Vector3 extents;
		uint32_t unk1;
	};

	// 0x52
	struct MaterialSort_t {
		uint16_t textureData;
		uint16_t lightmapHeader;
		uint16_t cubemap;
		uint16_t unk;
		uint32_t vertexOffset;
	};

	// 0x5C
	struct Brush_t {
		Vector3 origin;
		uint16_t flags;
		uint16_t index;
		Vector3 extents;
		uint32_t sidePlane;
	};

	// 0x77
	struct CellAABBNode_t {
		Vector3 mins;
		uint8_t childCount;
		uint8_t objRefCount;
		uint16_t totalRefCount;
		Vector3 maxs;
		uint16_t firstChild;
		uint16_t objRef;
	};

	// 0x7B
	struct LevelInfo_t {
		uint32_t unk0;
		uint32_t unk1;
		uint32_t unk3;
		uint32_t propCount;
		Vector3 unk2;
	};

	// 0x79
	struct ObjReferenceBounds_t {
		Vector3 mins;
		uint32_t zero0;
		Vector3 maxs;
		uint32_t zero1;
	};


	namespace Bsp {
		inline std::vector<char> entities;
		inline std::vector<Plane3f> planes;
		inline std::vector<TextureData_t> textureData;
		inline std::vector<Vector3> vertices;
		inline std::vector<Model_t> models;
		inline std::vector<char> entityPartitions;
		inline std::vector<Vector3> vertexNormals;
		inline std::vector<char> textureDataData;
		inline std::vector<uint32_t> textureDataTable;
		inline std::vector<VertexLitBump_t> vertexLitBumpVertices;
		inline std::vector<uint16_t> meshIndices;
		inline std::vector<Mesh_t> meshes;
		inline std::vector<MeshBounds_t> meshBounds;
		inline std::vector<MaterialSort_t> materialSorts;
		inline std::vector<Brush_t> cmBrushes;
		inline std::vector<CellAABBNode_t> cellAABBNodes;
		inline std::vector<uint16_t> objReferences;
		inline std::vector<ObjReferenceBounds_t> objReferenceBounds;
		// Only one entry! used a vector to keep load / save code simple
		inline std::vector<LevelInfo_t> levelInfo;
	}
}