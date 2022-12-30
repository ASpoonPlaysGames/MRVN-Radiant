/* -------------------------------------------------------------------------------

   My feeble attempt at generating a r1 ( Titanfall1 ) .bsp file.

   A lot of this is temporary and will be altered heavily with new information.
   If you know how to c++ better than me feel free to contribute or call me words
   in discord. :)

   - Fifty#8113, also known as Fifteen, Sixteen, Seventeen, Eigtheen and FORTY

   ------------------------------------------------------------------------------- */


/* dependencies */
#include "bspfile_abstract.h"
#include <ctime>


/* constants */
#define R1_LUMP_ENTITIES                                0x00
#define R1_LUMP_PLANES                                  0x01
#define R1_LUMP_TEXTURE_DATA                            0x02
#define R1_LUMP_VERTICES                                0x03
#define R1_LUMP_MODELS                                  0x0E
#define R1_LUMP_ENTITY_PARTITIONS                       0x18
#define R1_LUMP_PHYSICS_COLLIDE                         0x1D
#define R1_LUMP_VERTEX_NORMALS                          0x1E
#define R1_LUMP_GAME_LUMP                               0x23
#define R1_LUMP_LEAF_WATER_DATA                         0x24
#define R1_LUMP_PAKFILE                                 0x28
#define R1_LUMP_CUBEMAPS                                0x2A
#define R1_LUMP_TEXTURE_DATA_STRING_DATA                0x2B
#define R1_LUMP_TEXTURE_DATA_STRING_TABLE               0x2C
#define R1_LUMP_WORLD_LIGHTS                            0x36
#define R1_LUMP_PHYSICS_LEVEL                           0x3E
#define R1_LUMP_TRICOLL_TRIS                            0x42
#define R1_LUMP_TRICOLL_NODES                           0x44
#define R1_LUMP_TRICOLL_HEADERS                         0x45
#define R1_LUMP_PHYSICS_TRIANGLES                       0x46
#define R1_LUMP_VERTEX_UNLIT                            0x47
#define R1_LUMP_VERTEX_LIT_FLAT                         0x48
#define R1_LUMP_VERTEX_LIT_BUMP                         0x49
#define R1_LUMP_VERTEX_UNLIT_TS                         0x4A
#define R1_LUMP_VERTEX_BLINN_PHONG                      0x4B
#define R1_LUMP_VERTEX_RESERVED_5                       0x4C
#define R1_LUMP_VERTEX_RESERVED_6                       0x4D
#define R1_LUMP_VERTEX_RESERVED_7                       0x4E
#define R1_LUMP_MESH_INDICES                            0x4F
#define R1_LUMP_MESHES                                  0x50
#define R1_LUMP_MESH_BOUNDS                             0x51
#define R1_LUMP_MATERIAL_SORT                           0x52
#define R1_LUMP_LIGHTMAP_HEADERS                        0x53
#define R1_LUMP_CM_GRID                                 0x55
#define R1_LUMP_CM_GRID_CELLS                           0x56
#define R1_LUMP_CM_GRID_SETS                            0x57
#define R1_LUMP_CM_GEO_SET_BOUNDS                       0x58
#define R1_LUMP_CM_PRIMITIVES                           0x59
#define R1_LUMP_CM_PRIMITIVE_BOUNDS                     0x5A
#define R1_LUMP_CM_UNIQUE_CONTENTS                      0x5B
#define R1_LUMP_CM_BRUSHES                              0x5C
#define R1_LUMP_CM_BRUSH_SIDE_PLANE_OFFSETS             0x5D
#define R1_LUMP_CM_BRUSH_SIDE_PROPS                     0x5E
#define R1_LUMP_CM_BRUSH_TEX_VECS                       0x5F
#define R1_LUMP_TRICOLL_BEVEL_STARTS                    0x60
#define R1_LUMP_TRICOLL_BEVEL_INDICES                   0x61
#define R1_LUMP_LIGHTMAP_DATA_SKY                       0x62
#define R1_LUMP_CSM_AABB_NODES                          0x63
#define R1_LUMP_CSM_OBJ_REFERENCES                      0x64
#define R1_LUMP_LIGHTPROBES                             0x65
#define R1_LUMP_STATIC_PROP_LIGHTPROBE_INDICES          0x66
#define R1_LUMP_LIGHTPROBE_TREE                         0x67
#define R1_LUMP_LIGHTPROBE_REFERENCES                   0x68
#define R1_LUMP_LIGHTMAP_DATA_REAL_TIME_LIGHTS          0x69
#define R1_LUMP_CELL_BSP_NODES                          0x6A
#define R1_LUMP_CELLS                                   0x6B
#define R1_LUMP_PORTALS                                 0x6C
#define R1_LUMP_PORTAL_VERTICES                         0x6D
#define R1_LUMP_PORTAL_EDGES                            0x6E
#define R1_LUMP_PORTAL_VERTEX_EDGES                     0x6F
#define R1_LUMP_PORTAL_VERTEX_REFERENCES                0x70
#define R1_LUMP_PORTAL_EDGE_REGERENCES                  0x71
#define R1_LUMP_PORTAL_EDGE_INTERSECT_AT_EDGE           0x72
#define R1_LUMP_PORTAL_EDGE_INTERSECT_AT_VERTEX         0x73
#define R1_LUMP_PORTAL_EDGE_INTERSECT_HEADER            0x74
#define R1_LUMP_OCCLUSION_MESH_VERTICES                 0x75
#define R1_LUMP_OCCLUSION_MESH_INDICES                  0x76
#define R1_LUMP_CELL_AABB_NODES                         0x77
#define R1_LUMP_OBJ_REFERENCES                          0x78
#define R1_LUMP_OBJ_REFERENCE_BOUNDS                    0x79
#define R1_LUMP_LEVEL_INFO                              0x7B
#define R1_LUMP_SHADOW_MESH_OPAQUE_VERTICES             0x7C
#define R1_LUMP_SHADOW_MESH_ALPHA_VERTICES              0x7D
#define R1_LUMP_SHADOW_MESH_INDICES                     0x7E
#define R1_LUMP_SHADOW_MESHES                           0x7F


/*
   LoadR2BSPFile()
   loads a r1 bsp file
*/
void LoadR1BSPFile(const char* filename) {}


/*
   WriteR2BSPFile()
   writes a r1 bsp file
*/
void WriteR1BSPFile(const char* filename) {
    rbspHeader_t header{};

    // Set up header
    memcpy(header.ident, g_game->bspIdent, 4);
    header.version = LittleLong(g_game->bspVersion);
    header.mapVersion = 6;
    header.maxLump = 127;

    // This should be automated maybe
    header.lumps[0x02].lumpVer = 1;
    header.lumps[0x36].lumpVer = 1;
    header.lumps[0x49].lumpVer = 1;
    header.lumps[0x53].lumpVer = 1;

    // write initial header
    FILE* file = SafeOpenWrite(filename);
    SafeWrite(file, &header, sizeof(header));

    {
        char message[64] = "Built with love using MRVN-radiant :)";
        SafeWrite(file, &message, sizeof(message));
    }
    {
        char message[64];
        strncpy(message,StringOutputStream(64)("Version:        ", Q3MAP_VERSION).c_str(), 64);
        SafeWrite(file, &message, sizeof(message));
    }
    {
        time_t t;
        time(&t);
        char message[64];
        strncpy(message,StringOutputStream(64)("Time:           ", asctime(localtime(&t))).c_str(), 64);
        SafeWrite(file, &message, sizeof(message));
    }

    /* Write lumps */
    AddLump(file, header.lumps[R1_LUMP_ENTITIES],          Titanfall::Bsp::entities);
    AddLump(file, header.lumps[R1_LUMP_PLANES],            Titanfall::Bsp::planes);
    AddLump(file, header.lumps[R1_LUMP_TEXTURE_DATA],      Titanfall::Bsp::textureData);
    AddLump(file, header.lumps[R1_LUMP_VERTICES],          Titanfall::Bsp::vertices);
    AddLump(file, header.lumps[R1_LUMP_MODELS],            Titanfall::Bsp::models);
    AddLump(file, header.lumps[R1_LUMP_ENTITY_PARTITIONS], Titanfall::Bsp::entityPartitions);
    AddLump(file, header.lumps[R1_LUMP_PHYSICS_COLLIDE],   Titanfall::Bsp::physicsCollide_stub);  // stub
    AddLump(file, header.lumps[R1_LUMP_VERTEX_NORMALS],    Titanfall::Bsp::vertexNormals);
    // GameLump Stub
    {
        header.lumps[R1_LUMP_GAME_LUMP].offset = ftell(file);
        header.lumps[R1_LUMP_GAME_LUMP].length = 40;

        Titanfall::GameLump_Stub_t gameLump_stub;
        SafeWrite(file, &gameLump_stub.version, 4);
        memcpy(gameLump_stub.magic, "prps", 4);
        SafeWrite(file, &gameLump_stub.magic, 4);
        SafeWrite(file, &gameLump_stub.const0, 4);
        gameLump_stub.offset = LittleLong(ftell(file) + 8);
        SafeWrite(file, &gameLump_stub.offset, 4);
        SafeWrite(file, &gameLump_stub.length, 4);
        SafeWrite(file, &gameLump_stub.zeros, 20);
    }
    AddLump(file, header.lumps[R1_LUMP_TEXTURE_DATA_STRING_DATA],    Titanfall::Bsp::textureDataData);
    AddLump(file, header.lumps[R1_LUMP_TEXTURE_DATA_STRING_TABLE],   Titanfall::Bsp::textureDataTable);
    AddLump(file, header.lumps[R1_LUMP_WORLD_LIGHTS],                Titanfall::Bsp::worldLights_stub);  // stub
    AddLump(file, header.lumps[R1_LUMP_VERTEX_UNLIT],                Titanfall::Bsp::vertexUnlitVertices);
    AddLump(file, header.lumps[R1_LUMP_VERTEX_LIT_FLAT],             Titanfall::Bsp::vertexLitFlatVertices);
    AddLump(file, header.lumps[R1_LUMP_VERTEX_LIT_BUMP],             Titanfall::Bsp::vertexLitBumpVertices);
    AddLump(file, header.lumps[R1_LUMP_VERTEX_UNLIT_TS],             Titanfall::Bsp::vertexUnlitTSVertices);
    AddLump(file, header.lumps[R1_LUMP_VERTEX_BLINN_PHONG],          Titanfall::Bsp::vertexBlinnPhongVertices);
    AddLump(file, header.lumps[R1_LUMP_MESH_INDICES],                Titanfall::Bsp::meshIndices);
    AddLump(file, header.lumps[R1_LUMP_MESHES],                      Titanfall::Bsp::meshes);
    AddLump(file, header.lumps[R1_LUMP_MESH_BOUNDS],                 Titanfall::Bsp::meshBounds);
    AddLump(file, header.lumps[R1_LUMP_MATERIAL_SORT],               Titanfall::Bsp::materialSorts);
    AddLump(file, header.lumps[R1_LUMP_LIGHTMAP_HEADERS],            Titanfall::Bsp::lightmapHeaders_stub);  // stub
    AddLump(file, header.lumps[R1_LUMP_CM_GRID],                     Titanfall::Bsp::cmGrid);
    AddLump(file, header.lumps[R1_LUMP_CM_GRID_CELLS],               Titanfall::Bsp::cmGridCells);
    AddLump(file, header.lumps[R1_LUMP_CM_GRID_SETS],                Titanfall::Bsp::cmGeoSets);
    AddLump(file, header.lumps[R1_LUMP_CM_GEO_SET_BOUNDS],           Titanfall::Bsp::cmGeoSetBounds);
    AddLump(file, header.lumps[R1_LUMP_CM_UNIQUE_CONTENTS],          Titanfall::Bsp::cmUniqueContents_stub);  // stub
    AddLump(file, header.lumps[R1_LUMP_CM_BRUSHES],                  Titanfall::Bsp::cmBrushes);
    AddLump(file, header.lumps[R1_LUMP_CM_BRUSH_SIDE_PROPS],         Titanfall::Bsp::cmBrushSideProperties);
    AddLump(file, header.lumps[R1_LUMP_CM_BRUSH_SIDE_PLANE_OFFSETS], Titanfall::Bsp::cmBrushSidePlaneOffsets);
    AddLump(file, header.lumps[R1_LUMP_LIGHTMAP_DATA_SKY],           Titanfall::Bsp::lightMapDataSky_stub);  // stub
    AddLump(file, header.lumps[R1_LUMP_CSM_AABB_NODES],              Titanfall::Bsp::csmAABBNodes_stub);  // stub
    AddLump(file, header.lumps[R1_LUMP_CELL_BSP_NODES],              Titanfall::Bsp::cellBSPNodes_stub);  // stub
    AddLump(file, header.lumps[R1_LUMP_CELLS],                       Titanfall::Bsp::cells_stub);  // stub
    AddLump(file, header.lumps[R1_LUMP_CELL_AABB_NODES],             Titanfall::Bsp::cellAABBNodes);
    AddLump(file, header.lumps[R1_LUMP_OBJ_REFERENCES],              Titanfall::Bsp::objReferences);
    AddLump(file, header.lumps[R1_LUMP_OBJ_REFERENCE_BOUNDS],        Titanfall::Bsp::objReferenceBounds);
    AddLump(file, header.lumps[R1_LUMP_LEVEL_INFO],                  Titanfall::Bsp::levelInfo);

    /* emit bsp size */
    const int size = ftell(file);
    Sys_Printf("Wrote %.1f MB (%d bytes)\n", (float)size / (1024 * 1024), size);

    /* write the completed header */
    fseek(file, 0, SEEK_SET);
    SafeWrite(file, &header, sizeof(header));

    /* close the file */
    fclose(file);
}


/*
    CompileR1BSPFile
    Compiles a v29 bsp file
*/
void CompileR1BSPFile() {
    for (std::size_t entityNum = 0; entityNum < entities.size(); ++entityNum) {
        // Get entity
        entity_t& entity = entities[entityNum];
        const char* classname = entity.classname();

        Titanfall::EmitEntity(entity);

        // Visible geo
        if (striEqual(classname, "worldspawn")) {
            Titanfall::BeginModel();
            // Generate bsp meshes from map brushes
            Shared::MakeMeshes(entity);

            Titanfall::EmitMeshes(entity);

            Titanfall::EmitBrushes(entity);

            Titanfall::EndModel();
        }
    }

    Titanfall::EmitEntityPartitions();

    Shared::MakeVisReferences();
    Shared::visRoot = Shared::MakeVisTree(Shared::visRefs, 1e30f);
    Titanfall::EmitVisTree();

    Titanfall::EmitLevelInfo();

    Titanfall::EmitCollisionGrid();

    Titanfall::EmitStubs();
}


/*
   EmitEntity()
   Saves an entity into it's corresponding .ent file or the lump in the .bsp
*/
void Titanfall::EmitEntity(const entity_t &e) {
    StringOutputStream data;
    data << "{\n";
    for (const epair_t& pair : e.epairs)
        data << "\"" << pair.key.c_str() << "\" \"" << pair.value.c_str() << "\"\n";
    data << "}\n";

    std::vector<char> str = { data.begin(), data.end() };

    // TODO: un-hardcode this. somehow...
    // NOTE: classname -> editorclass & exclusions should have already been done
    // -- e.g. prop_static -> game lump, light -> worldlights
    const char *classname = e.classname();
    #define ENT_IS(x)  striEqual(classname, x)
    #define ENT_STARTS(x)  striEqualPrefix(classname, x)
    // env
    if (ENT_IS("env_fog_controler") || ENT_IS("sky_camera")) {
        Titanfall::Ent::env.insert(Titanfall::Ent::env.end(), str.begin(), str.end());
    // fx
    } else if (ENT_IS("beam_spotlight") || ENT_IS("env_sprite_clientside") || ENT_IS("info_particle_system")) {
        // TODO: info_target (editorclass="info_target_fx")
        // TODO: info_target_clientside (editorclass="info_target_fx_clientside")
        Titanfall::Ent::fx.insert(Titanfall::Ent::fx.end(), str.begin(), str.end());
    // script
    } else if (ENT_IS("assault_assaultpoint") || ENT_IS("info_hardpoint")     || ENT_IS("info_hint")
            || ENT_STARTS("info_node")        || ENT_IS("info_target")        || ENT_IS("info_target_clientside")
            || ENT_IS("path_track")           || ENT_IS("prop_control_panel") || ENT_IS("prop_dynamic")
            || ENT_IS("prop_refuel_pump")     || ENT_IS("script_ref")         || ENT_IS("traverse")) {
        Titanfall::Ent::script.insert(Titanfall::Ent::script.end(), str.begin(), str.end());
    // snd
    } else if (ENT_IS("ambient_generic")) {
        Titanfall::Ent::script.insert(Titanfall::Ent::snd.end(), str.begin(), str.end());
    // spawn
    } else if (ENT_IS("info_frontline") || ENT_STARTS("info_spawnpoint_")) {
        Titanfall::Ent::spawn.insert(Titanfall::Ent::spawn.end(), str.begin(), str.end());
    }
    else {
        // bsp entity lump
        Titanfall::Bsp::entities.insert(Titanfall::Bsp::entities.end(), str.begin(), str.end());
    }
    #undef ENT_IS
    #undef ENT_STARTS
}


/*
    EmitTriggerBrushPlaneKeyValues()
    Emits brush planes as keyvalues because respawn
*/
void Titanfall::EmitTriggerBrushPlaneKeyValues(entity_t &e) {
    std::size_t b = 0;
    for (const brush_t &brush : e.brushes) {
        for (std::size_t s = 0; s < brush.sides.size(); s++) {
            const side_t &side = brush.sides.at(s);
            StringOutputStream key;
            key << "*trigger_brush_"
                << b
                << "_plane_"w
                << s;

            StringOutputStream value;
            value << side.plane.a
                  << " "
                  << side.plane.b
                  << " "
                  << side.plane.c
                  << " "
                  << side.plane.d;


            e.setKeyValue(key.c_str(), value.c_str());
        }
        b++;
    }
}


/*
    EmitTextureData()
    Emits texture data and returns its index
*/
uint32_t Titanfall::EmitTextureData(shaderInfo_t shader) {
    std::string tex = shader.shader.c_str();
    std::size_t index;

    // Strip 'textures/'
    tex.erase(tex.begin(), tex.begin() + strlen("textures/"));
    std::replace(tex.begin(), tex.end(), '/', '\\');  // Do we even need to do this ?

    // Check if it's already saved
    std::string table = std::string(Titanfall::Bsp::textureDataData.begin(), Titanfall::Bsp::textureDataData.end());
    index = table.find(tex);
    if (index != std::string::npos) {
        // Is already saved, find the index of its textureData

        for (std::size_t i = 0; i < Titanfall::Bsp::textureData.size(); i++) {
            Titanfall::TextureData_t &td = Titanfall::Bsp::textureData.at(i);
            uint32_t &tdt = Titanfall::Bsp::textureDataTable.at(td.name_index);

            if (tdt == index)
                return i;
        }
    }

    // Wasn't already saved, save it
    index = Titanfall::Bsp::textureData.size();

    // Add to Table
    StringOutputStream data;
    data << tex.c_str();
    std::vector<char> str = { data.begin(), data.end() + 1 };

    Titanfall::Bsp::textureDataTable.emplace_back(Titanfall::Bsp::textureDataData.size());
    Titanfall::Bsp::textureDataData.insert(Titanfall::Bsp::textureDataData.end(), str.begin(), str.end());

    Titanfall::TextureData_t &td = Titanfall::Bsp::textureData.emplace_back();
    td.name_index = Titanfall::Bsp::textureDataTable.size() - 1;
    td.sizeX = shader.shaderImage->width;
    td.sizeY = shader.shaderImage->height;
    td.visibleX = shader.shaderImage->width;
    td.visibleY = shader.shaderImage->height;
    td.flags = shader.surfaceFlags;

    return index;
}


/*
   EmitObjReferences()
   writes obj references used by vis tree
*/
void EmitObjReferences() {
    /* Meshes */
    for (uint16_t i = 0; i < Titanfall::Bsp::meshBounds.size(); i++) {
        Titanfall::MeshBounds_t mesh = Titanfall::Bsp::meshBounds.at(i);

        Titanfall::ObjReferenceBounds_t& refBounds = Titanfall::Bsp::objReferenceBounds.emplace_back();
        refBounds.mins = mesh.origin - mesh.extents;
        refBounds.maxs = mesh.origin + mesh.extents;

        uint16_t& ref = Titanfall::Bsp::objReferences.emplace_back();
        ref = i;
    }

    /* Props */
    // for (uint16_t i = 0; i < Titanfall2GameLump.propCount; i++) {
    //     Titanfall::ObjReferenceBounds_t& refBounds = Titanfall::Bsp::objReferenceBounds.emplace_back();
    //     refBounds.mins = Vector3(-1000, -1000, -1000);
    //     refBounds.maxs = Vector3(1000, 1000, 1000);

    //     uint16_t& ref = Titanfall::Bsp::objReferences.emplace_back();
    //     ref = Titanfall::Bsp::meshBounds.size() + i;
    // }
}


std::size_t Titanfall::EmitObjReferences(Shared::visNode_t& node) {
    // Sys_Printf("amongus\n");
    // for (std::size_t i = 0; i < Titanfall::Bsp::objReferences.size(); i++)
    //     if (Titanfall::Bsp::objReferences.at(i) == ref.index)
    //         return i;

    for (Shared::visRef_t& ref : node.refs) {
        Titanfall::ObjReferenceBounds_t& rb = Titanfall::Bsp::objReferenceBounds.emplace_back();
        rb.maxs = ref.minmax.maxs;
        rb.mins = ref.minmax.mins;

        Titanfall::Bsp::objReferences.emplace_back(ref.index);
    }

    return Titanfall::Bsp::objReferences.size() - node.refs.size();
}


uint16_t GetTotalVisRefCount(Shared::visNode_t node) {
    uint16_t count = node.refs.size();
    for (Shared::visNode_t& n : node.children)
            count += GetTotalVisRefCount(n);
    return count;
}


uint16_t GetTotalVisNodeChildCount(Shared::visNode_t node) {
    uint16_t count = node.children.size();
    for (Shared::visNode_t& n : node.children)
            count += GetTotalVisNodeChildCount(n);
    return count;
}


int Titanfall::EmitVisChildrenOfTreeNode(Shared::visNode_t node) {
    int index = Titanfall::Bsp::cellAABBNodes.size();  // Index of first child of node

    for (std::size_t i = 0; i < node.children.size(); i++) {
        Shared::visNode_t& n = node.children.at(i);

        Titanfall::CellAABBNode_t& bn = Titanfall::Bsp::cellAABBNodes.emplace_back();
        bn.maxs = n.minmax.maxs;
        bn.mins = n.minmax.mins;
        bn.childCount = n.children.size();
        bn.totalRefCount = GetTotalVisRefCount(n);

        if (n.refs.size()) {
            bn.objRef = Titanfall::EmitObjReferences(n);
            bn.objRefCount = n.refs.size();
        }
    }

    for (std::size_t i = 0; i < node.children.size(); i++) {
        int firstChild = Titanfall::EmitVisChildrenOfTreeNode(node.children.at(i));

        Titanfall::CellAABBNode_t& bn = Titanfall::Bsp::cellAABBNodes.at(index + i);
        bn.firstChild = firstChild;
    }

    return index;
}


void Titanfall::EmitVisTree() {
    Shared::visNode_t& root = Shared::visRoot;

    Titanfall::CellAABBNode_t& bn = Titanfall::Bsp::cellAABBNodes.emplace_back();
    bn.maxs = root.minmax.maxs;
    bn.mins = root.minmax.mins;
    bn.firstChild = Titanfall::Bsp::cellAABBNodes.size();
    bn.childCount = root.children.size();
    bn.totalRefCount = GetTotalVisRefCount(root);
    if (root.refs.size()) {
        bn.objRef = EmitObjReferences(root);
        bn.objRefCount = root.refs.size();
    }

    EmitVisChildrenOfTreeNode(Shared::visRoot);
}


/*
    EmitVertex
    Saves a vertex into Titanfall::vertices and returns its index
*/
uint32_t Titanfall::EmitVertex(Vector3 &vertex) {
    for (uint32_t i = 0; i < (uint32_t)Titanfall::Bsp::vertices.size(); i++) {
        if (VectorCompare(vertex, Titanfall::Bsp::vertices.at(i)))
            return i;
    }

    Titanfall::Bsp::vertices.emplace_back(vertex);
    return (uint32_t)Titanfall::Bsp::vertices.size() - 1;
}


/*
    EmitVertexNormal
    Saves a vertex normal into Titanfall::vertexNormals and returns its index
*/
uint32_t Titanfall::EmitVertexNormal(Vector3 &normal) {
    for (uint32_t i = 0; i < (uint32_t)Titanfall::Bsp::vertexNormals.size(); i++) {
        if (VectorCompare(normal, Titanfall::Bsp::vertexNormals.at(i)))
            return i;
    }

    Titanfall::Bsp::vertexNormals.emplace_back(normal);
    return (uint32_t)Titanfall::Bsp::vertexNormals.size() - 1;
}


/*
    BeginModel()
    Creates a new model entry
*/
void Titanfall::BeginModel() {
    Titanfall::Model_t &model = Titanfall::Bsp::models.emplace_back();
    model.firstMesh = (uint32_t)Titanfall::Bsp::meshes.size();
}


/*
    EndModel()
    Fills the last model entry
*/
void Titanfall::EndModel() {
    Titanfall::Model_t &model = Titanfall::Bsp::models.back();
    model.meshCount = (uint32_t)Titanfall::Bsp::meshes.size() - model.firstMesh;

    for (Titanfall::MeshBounds_t &meshBounds : Titanfall::Bsp::meshBounds) {
        model.minmax.extend(meshBounds.origin - meshBounds.extents);
        model.minmax.extend(meshBounds.origin + meshBounds.extents);
    }
}


/*
    EmitEntityPartitions()
    Writes entitiy partitions respawn uses
*/
void Titanfall::EmitEntityPartitions() {
    std::string partitions = "01*";

    if (Titanfall::Ent::env.size())
        partitions += " env";
    if (Titanfall::Ent::fx.size())
        partitions += " fx";
    if (Titanfall::Ent::script.size())
        partitions += " script";
    if (Titanfall::Ent::snd.size())
        partitions += " snd";
    if (Titanfall::Ent::spawn.size())
        partitions += " spawn";

    Titanfall::Bsp::entityPartitions = { partitions.begin(), partitions.end() + 1 };
}


/*
    EmitVertexUnlit
    Saves a vertex into Titanfall::Bsp::vertexUnlitVertices
*/
void Titanfall::EmitVertexUnlit(Shared::Vertex_t &vertex) {
    Titanfall::VertexUnlit_t &ul = Titanfall::Bsp::vertexUnlitVertices.emplace_back();
    ul.vertexIndex = Titanfall::EmitVertex(vertex.xyz);
    ul.normalIndex = Titanfall::EmitVertexNormal(vertex.normal);
    ul.uv0 = vertex.st;
}


/*
    EmitVertexLitFlat
    Saves a vertex into Titanfall::Bsp::vertexLitFlatVertices
*/
void Titanfall::EmitVertexLitFlat(Shared::Vertex_t &vertex) {
    Titanfall::VertexLitFlat_t &lf = Titanfall::Bsp::vertexLitFlatVertices.emplace_back();
    lf.vertexIndex = Titanfall::EmitVertex(vertex.xyz);
    lf.normalIndex = Titanfall::EmitVertexNormal(vertex.normal);
    lf.uv0 = vertex.st;
}


/*
    EmitVertexLitBump
    Saves a vertex into Titanfall::Bsp::vertexLitBumpVertices
*/
void Titanfall::EmitVertexLitBump(Shared::Vertex_t &vertex) {
    Titanfall::VertexLitBump_t &lv = Titanfall::Bsp::vertexLitBumpVertices.emplace_back();
    lv.vertexIndex = Titanfall::EmitVertex(vertex.xyz);
    lv.normalIndex = Titanfall::EmitVertexNormal(vertex.normal);
    lv.uv0 = vertex.st;
    lv.negativeOne = -1;
}


/*
    EmitVertexUnlitTS
    Saves a vertex into Titanfall::Bsp::vertexUnlitTSVertices
*/
void Titanfall::EmitVertexUnlitTS(Shared::Vertex_t &vertex) {
    Titanfall::VertexUnlitTS_t &ul = Titanfall::Bsp::vertexUnlitTSVertices.emplace_back();
    ul.vertexIndex = Titanfall::EmitVertex(vertex.xyz);
    ul.normalIndex = Titanfall::EmitVertexNormal(vertex.normal);
    ul.uv0 = vertex.st;
}


/*
    EmitVertexBlinnPhong
    Saves a vertex into Titanfall::Bsp::vertexBlinnPhongVertices
*/
void Titanfall::EmitVertexBlinnPhong(Shared::Vertex_t &vertex) {
    Titanfall::VertexBlinnPhong_t &bp = Titanfall::Bsp::vertexBlinnPhongVertices.emplace_back();
    bp.vertexIndex = Titanfall::EmitVertex(vertex.xyz);
    bp.normalIndex = Titanfall::EmitVertexNormal(vertex.normal);
}


/*
    EmitMeshes()
    writes the mesh list to the bsp
*/
void Titanfall::EmitMeshes(const entity_t &e) {
    for (const Shared::Mesh_t &mesh : Shared::meshes) {
        Titanfall::Mesh_t &bm = Titanfall::Bsp::meshes.emplace_back();
        bm.const0 = 4294967040;  // :)
        bm.flags = mesh.shaderInfo->surfaceFlags;
        bm.firstVertex = Titanfall::Bsp::vertexLitBumpVertices.size();
        bm.vertexCount = mesh.vertices.size();
        bm.triOffset = Titanfall::Bsp::meshIndices.size();
        bm.triCount = mesh.triangles.size() / 3;

        // Emit textrue related structs
        uint32_t textureIndex = Titanfall::EmitTextureData(*mesh.shaderInfo);
        bm.materialOffset = Titanfall::EmitMaterialSort(textureIndex);
        MinMax aabb;

        // Save vertices and vertexnormals
        for (std::size_t i = 0; i < mesh.vertices.size(); i++) {
            Shared::Vertex_t vertex = mesh.vertices.at(i);

            // Check against aabb
            aabb.extend(vertex.xyz);

            if (mesh.shaderInfo->surfaceFlags & S_VERTEX_LIT_BUMP)
                Titanfall::EmitVertexLitBump(vertex);
            else if (mesh.shaderInfo->surfaceFlags & S_VERTEX_UNLIT)
                Titanfall::EmitVertexUnlit(vertex);
            else if (mesh.shaderInfo->surfaceFlags & S_VERTEX_UNLIT_TS)
                Titanfall::EmitVertexUnlitTS(vertex);
            else
                Titanfall::EmitVertexLitFlat(vertex);
        }

        // Save triangles
        for (uint16_t triangle : mesh.triangles) {
            uint32_t totalVertices = 0;
            if (mesh.shaderInfo->surfaceFlags & S_VERTEX_LIT_BUMP)
                totalVertices = Titanfall::Bsp::vertexLitBumpVertices.size();
            else if (mesh.shaderInfo->surfaceFlags & S_VERTEX_UNLIT)
                totalVertices = Titanfall::Bsp::vertexUnlitVertices.size();
            else if (mesh.shaderInfo->surfaceFlags & S_VERTEX_UNLIT_TS)
                totalVertices = Titanfall::Bsp::vertexUnlitTSVertices.size();
            else
                totalVertices = Titanfall::Bsp::vertexLitFlatVertices.size();

            for (uint32_t j = 0; j < totalVertices; j++) {
                uint32_t vertexIndex = 0;
                uint32_t normalIndex = 0;

                if (mesh.shaderInfo->surfaceFlags & S_VERTEX_LIT_BUMP) {
                    vertexIndex = Titanfall::Bsp::vertexLitBumpVertices.at(j).vertexIndex;
                    normalIndex = Titanfall::Bsp::vertexLitBumpVertices.at(j).normalIndex;
                } else if (mesh.shaderInfo->surfaceFlags & S_VERTEX_UNLIT) {
                    vertexIndex = Titanfall::Bsp::vertexUnlitVertices.at(j).vertexIndex;
                    normalIndex = Titanfall::Bsp::vertexUnlitVertices.at(j).normalIndex;
                } else if (mesh.shaderInfo->surfaceFlags & S_VERTEX_UNLIT_TS) {
                    vertexIndex = Titanfall::Bsp::vertexUnlitTSVertices.at(j).vertexIndex;
                    normalIndex = Titanfall::Bsp::vertexUnlitTSVertices.at(j).normalIndex;
                } else {
                    vertexIndex = Titanfall::Bsp::vertexLitFlatVertices.at(j).vertexIndex;
                    normalIndex = Titanfall::Bsp::vertexLitFlatVertices.at(j).normalIndex;
                }

                if (!VectorCompare(Titanfall::Bsp::vertices.at(vertexIndex), mesh.vertices.at(triangle).xyz))
                    continue;

                if (!VectorCompare(Titanfall::Bsp::vertexNormals.at(normalIndex), mesh.vertices.at(triangle).normal))
                    continue;

                uint16_t& index = Titanfall::Bsp::meshIndices.emplace_back();
                index = j;
                break;
            }
        }

        // Save MeshBounds
        Titanfall::MeshBounds_t& mb = Titanfall::Bsp::meshBounds.emplace_back();
        mb.origin = (aabb.maxs + aabb.mins) / 2;
        mb.extents = (aabb.maxs - aabb.mins) / 2;
    }
}


/*
    EmitMaterialSort()
    Tries to create a material sort of the last texture
*/
uint16_t Titanfall::EmitMaterialSort(uint32_t index) {
    /* Check if the material sort we need already exists */
    std::size_t pos = 0;
    for (Titanfall::MaterialSort_t &ms : Titanfall::Bsp::materialSorts) {
        if (ms.textureData == index)
            return pos;

        pos++;
    }

    Titanfall::MaterialSort_t &ms = Titanfall::Bsp::materialSorts.emplace_back();
    ms.textureData = index;

    return pos;
}


/*
    EmitCollisionGrid()
    Emits brushes of entity into bsp
*/
void Titanfall::EmitCollisionGrid() {
    // Worldspawn size
    Vector3 size = Titanfall::Bsp::models[0].minmax.maxs - Titanfall::Bsp::models[0].minmax.mins;

    // Choose scale
    float scale = 256;
    {
        // 128 Is an arbitrary limit, I think there's one between 128 and 190 but havent tested much
        float xScale = size.x() / 128;
        float yScale = size.y() / 128;

        scale = ceil(xScale > yScale ? xScale : yScale);
        scale = scale < 256 ? 256 : scale;
    }

    Titanfall::CMGrid_t& grid = Titanfall::Bsp::cmGrid.emplace_back();
    grid.scale = scale;
    grid.xOffset = floor(Titanfall::Bsp::models[0].minmax.mins.x() / grid.scale) - 1;
    grid.yOffset = floor(Titanfall::Bsp::models[0].minmax.mins.y() / grid.scale) - 1;
    grid.xCount = ceil(size.x() / grid.scale) + 2;
    grid.yCount = ceil(size.y() / grid.scale) + 2;
    grid.unk2 = Titanfall::Bsp::cmBrushes.size();
    grid.brushSidePlaneOffset = 0;

    // Make GridCells
    for (int32_t y = 0; y < grid.yCount; y++) {
        for (int32_t x = 0; x < grid.xCount; x++) {
            MinMax cellMinmax;
            cellMinmax.mins = Vector3((x + grid.xOffset) * grid.scale,
                                      (y + grid.yOffset) * grid.scale,
                                      Titanfall::Bsp::models[0].minmax.mins.z());
            cellMinmax.maxs = Vector3((x + grid.xOffset + 1) * grid.scale,
                                      (y + grid.yOffset + 1) * grid.scale,
                                      Titanfall::Bsp::models[0].minmax.maxs.z());

            // Sys_Printf("Worldspawn: %f %f %f : %f %f %f\n",
            //            Titanfall::Bsp::models[0].minmax.mins.x(),
            //            Titanfall::Bsp::models[0].minmax.mins.y(),
            //            Titanfall::Bsp::models[0].minmax.mins.z(),
            //            Titanfall::Bsp::models[0].minmax.maxs.x(),
            //            Titanfall::Bsp::models[0].minmax.maxs.y(),
            //            Titanfall::Bsp::models[0].minmax.maxs.z());
            // Sys_Printf("Cell      : %f %f %f : %f %f %f\n",
            //            cellMinmax.mins.x(), cellMinmax.mins.y(), cellMinmax.mins.z(),
            //            cellMinmax.maxs.x(), cellMinmax.maxs.y(), cellMinmax.maxs.z());

            Titanfall::CMGridCell_t& cell = Titanfall::Bsp::cmGridCells.emplace_back();
            cell.start = Titanfall::Bsp::cmGeoSets.size();

            // Check brushes
            for (uint32_t index = 0; index < Titanfall::Bsp::cmBrushes.size(); index++) {
                Titanfall::CMBrush_t &brush = Titanfall::Bsp::cmBrushes.at(index);

                MinMax brushMinmax;
                brushMinmax.mins = brush.origin - brush.extents;
                brushMinmax.maxs = brush.origin + brush.extents;

                // NOTE: Still doesnt work
                if (!cellMinmax.test(brushMinmax))
                    continue;

                Titanfall::CMGeoSet_t& set = Titanfall::Bsp::cmGeoSets.emplace_back();
                set.unknown0 = 0;
                set.unknown1 = 1;
                set.unknown2 = 0;
                set.collisionShapeIndex = index;

                Titanfall::CMBound_t& bound = Titanfall::Bsp::cmGeoSetBounds.emplace_back();
                bound.unknown1 = 128;
                bound.origin = brush.origin;
                // The + 1.0f fixes the infinitely falling in one place while touching a floor bug
                bound.extents = Vector3(brush.extents.x() + 1.0f, brush.extents.y() + 1.0f, brush.extents.z() + 1.0f);
            }

            cell.count = Titanfall::Bsp::cmGeoSets.size() - cell.start;
        }
    }

    // Make GridCells for Models, why respawn ?
    for (Titanfall::Model_t &model : Titanfall::Bsp::models) {
        Titanfall::CMGridCell_t& cell = Titanfall::Bsp::cmGridCells.emplace_back();
        cell.start = Titanfall::Bsp::cmGeoSets.size();
        cell.count = 0;
    }
}


/*
    EmitBrushes()
    Emits brushes of entity into bsp
*/
void Titanfall::EmitBrushes(const entity_t& e) {
    uint16_t index = 0;
    for (const brush_t& brush : e.brushes) {
        Titanfall::CMBrush_t& b = Titanfall::Bsp::cmBrushes.emplace_back();

        b.extents = (brush.minmax.maxs - brush.minmax.mins) / 2;
        b.origin = brush.minmax.maxs - b.extents;
        b.index = index;
        b.planeCount = 0;
        b.unknown = 0;

        std::vector<side_t> axialSides;
        std::vector<side_t> cuttingSides;
        // +X -X +Y -Y +Z -Z
        bool axials[6];
        // The bsp brushes are AABBs + cutting planes
        // Surface flags are indexed first for AABB ( first 6 planes ) then for the rest
        // Radiant brushes are made purely of planes so we dont have a guarantee that we'll get the
        // Axial ones which define the AABB, that's why we first sort them
        for (const side_t &side : brush.sides) {
            Vector3 normal = side.plane.normal();
            SnapNormal(normal);
            if ((normal[0] == -1.0f || normal[0] == 1.0f || (normal[0] == 0.0f && normal[1] == 0.0f)
              || normal[1] == -1.0f || normal[1] == 1.0f || (normal[1] == 0.0f && normal[2] == 0.0f)
              || normal[2] == -1.0f || normal[2] == 1.0f || (normal[2] == 0.0f && normal[0] == 0.0f)) && !side.bevel) {
                // Axial
                axialSides.emplace_back(side);
            }
            // Not Axial
            cuttingSides.emplace_back(side);
        }

        for (const side_t &side : axialSides) {
            Vector3 normal = side.plane.normal();
            SnapNormal(normal);

            // +X
            if (normal[0] == 1.0f)
                axials[0] = true;
            // -X
            if (normal[0] == -1.0f)
                axials[1] = true;
            // +Y
            if (normal[1] == 1.0f)
                axials[2] = true;
            // -Y
            if (normal[1] == -1.0f)
                axials[3] = true;
            // +Z
            if (normal[2] == 1.0f)
                axials[4] = true;
            // -Z
            if (normal[2] == -1.0f)
                axials[5] = true;
        }

        // TODO: Add correct material offset
        int test = 0;
        for (int i = 0; i < 6; i++) {
            if (axials[i]) {
                Titanfall::Bsp::cmBrushSideProperties.emplace_back(1);
            } else {
                test++;
                Titanfall::Bsp::cmBrushSideProperties.emplace_back(0x4000);
            }
        }

#if 1
        for (const side_t &side : cuttingSides) {
            Vector3 normal = side.plane.normal();
            SnapNormal(normal);
            if (normal[0] == -1.0f || normal[0] == 1.0f || (normal[0] == 0.0f && normal[1] == 0.0f)
             || normal[1] == -1.0f || normal[1] == 1.0f || (normal[1] == 0.0f && normal[2] == 0.0f)
             || normal[2] == -1.0f || normal[2] == 1.0f || (normal[2] == 0.0f && normal[0] == 0.0f)) {
                continue;  // axial, only test non-axial edges
            }

            Titanfall::EmitPlane(side.plane);
            b.planeCount++;
            Titanfall::Bsp::cmBrushSideProperties.emplace_back(1);
            uint16_t& so = Titanfall::Bsp::cmBrushSidePlaneOffsets.emplace_back();
            so = 0;
        }

        if (b.planeCount) {
            b.unknown = b.planeCount / 2 + 1;
            b.sidePlaneIndex = Titanfall::Bsp::cmBrushSidePlaneOffsets.size() - b.planeCount;
        }
#endif
        index++;
    }
}


/*
    EmitPlane
*/
void Titanfall::EmitPlane(const Plane3 &plane) {
    Titanfall::Bsp::planes.emplace_back(Plane3f(plane));
}


/*
    EmitLevelInfo()
*/
void Titanfall::EmitLevelInfo() {
    Titanfall::LevelInfo_t &li = Titanfall::Bsp::levelInfo.emplace_back();

    li.firstDecalMeshIndex = li.firstTransMeshIndex = li.firstSkyMeshIndex = 0;

    // TODO: Add decal support
    for (Titanfall::Mesh_t &mesh : Titanfall::Bsp::meshes) {
        // if (mesh.flags & S_SKY)
        //     break;

        li.firstDecalMeshIndex++;
    }

    for (Titanfall::Mesh_t& mesh : Titanfall::Bsp::meshes) {
        // if (mesh.flags & S_TRANSLUCENT)
        //     break;

        li.firstTransMeshIndex++;
    }

    for (Titanfall::Mesh_t& mesh : Titanfall::Bsp::meshes) {
        // TODO: game shits itself when this is uncommented and your mesh is at the beginning of the vector
        //       Respawn probably sort their meshes by flags ?? VERIFY
        // if (mesh.flags & S_SKY)
        //     break;

        li.firstSkyMeshIndex++;
    }

    li.propCount = Titanfall2::GameLump.propCount;
}


/*
    EmitStubs
    Emits the lumps we cant generate yet, but need for the map to boot
*/
void Titanfall::EmitStubs() {
    {  // Physics Collide
        constexpr std::array<uint8_t, 2315> data = {
            0x00, 0x00, 0x00, 0x00, 0x64, 0x08, 0x00, 0x00, 0x87, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
            0x60, 0x08, 0x00, 0x00, 0x56, 0x50, 0x48, 0x59, 0x00, 0x01, 0x00, 0x00, 0x44, 0x08, 0x00, 0x00,
            0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00,
            0x4D, 0x58, 0x3C, 0xB4, 0x23, 0x51, 0xF1, 0xB4, 0x94, 0x00, 0xCE, 0xB3, 0x8E, 0x46, 0x99, 0x41,
            0x8E, 0x46, 0x99, 0x41, 0x8E, 0x46, 0x99, 0x41, 0x7A, 0x0D, 0x09, 0x41, 0xCE, 0x44, 0x08, 0x00,
            0x10, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x56, 0x50, 0x53,
            0xE0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x15, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
            0x00, 0xB0, 0x00, 0x01, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, 0x0F, 0x00, 0x02, 0x00, 0x08, 0x00,
            0x01, 0xA0, 0x00, 0x01, 0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x1B, 0x00, 0x01, 0x00, 0xFA, 0x7F,
            0x02, 0x90, 0x00, 0x02, 0x02, 0x00, 0x06, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00, 0xF8, 0x7F,
            0x03, 0x80, 0x00, 0x02, 0x02, 0x00, 0x06, 0x00, 0x05, 0x00, 0x20, 0x00, 0x04, 0x00, 0xFA, 0x7F,
            0x04, 0x70, 0x00, 0x01, 0x02, 0x00, 0xF1, 0x7F, 0x01, 0x00, 0x03, 0x00, 0x05, 0x00, 0xFA, 0x7F,
            0x05, 0x60, 0x00, 0x01, 0x05, 0x00, 0xFD, 0x7F, 0x01, 0x00, 0x0D, 0x00, 0x06, 0x00, 0x18, 0x00,
            0x06, 0x50, 0x00, 0x01, 0x00, 0x00, 0x06, 0x00, 0x07, 0x00, 0x0C, 0x00, 0x03, 0x00, 0xEA, 0x7F,
            0x07, 0x40, 0x00, 0x01, 0x00, 0x00, 0xED, 0x7F, 0x04, 0x00, 0x0B, 0x00, 0x07, 0x00, 0xFA, 0x7F,
            0x08, 0x30, 0x00, 0x01, 0x01, 0x00, 0xE5, 0x7F, 0x03, 0x00, 0x03, 0x00, 0x06, 0x00, 0xF3, 0x7F,
            0x09, 0x20, 0x00, 0x01, 0x06, 0x00, 0xFD, 0x7F, 0x03, 0x00, 0xF4, 0x7F, 0x07, 0x00, 0x04, 0x00,
            0x0A, 0x10, 0x00, 0x01, 0x07, 0x00, 0xF5, 0x7F, 0x04, 0x00, 0x03, 0x00, 0x06, 0x00, 0xFC, 0x7F,
            0x0B, 0x00, 0x00, 0x01, 0x06, 0x00, 0xFD, 0x7F, 0x04, 0x00, 0xE0, 0x7F, 0x05, 0x00, 0xE8, 0x7F,
            0x10, 0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x15, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
            0x00, 0xB0, 0x00, 0x02, 0x08, 0x00, 0x06, 0x00, 0x09, 0x00, 0x0F, 0x00, 0x0A, 0x00, 0x08, 0x00,
            0x01, 0xA0, 0x00, 0x02, 0x08, 0x00, 0x16, 0x00, 0x0B, 0x00, 0x1B, 0x00, 0x09, 0x00, 0xFA, 0x7F,
            0x02, 0x90, 0x00, 0x01, 0x0A, 0x00, 0x06, 0x00, 0x03, 0x00, 0x13, 0x00, 0x08, 0x00, 0xF8, 0x7F,
            0x03, 0x80, 0x00, 0x01, 0x0A, 0x00, 0x06, 0x00, 0x01, 0x00, 0x20, 0x00, 0x03, 0x00, 0xFA, 0x7F,
            0x04, 0x70, 0x00, 0x01, 0x0A, 0x00, 0xF1, 0x7F, 0x09, 0x00, 0x03, 0x00, 0x01, 0x00, 0xFA, 0x7F,
            0x05, 0x60, 0x00, 0x01, 0x01, 0x00, 0xFD, 0x7F, 0x09, 0x00, 0x0D, 0x00, 0x0C, 0x00, 0x18, 0x00,
            0x06, 0x50, 0x00, 0x01, 0x08, 0x00, 0x06, 0x00, 0x0D, 0x00, 0x0C, 0x00, 0x0B, 0x00, 0xEA, 0x7F,
            0x07, 0x40, 0x00, 0x01, 0x08, 0x00, 0xED, 0x7F, 0x03, 0x00, 0x0B, 0x00, 0x0D, 0x00, 0xFA, 0x7F,
            0x08, 0x30, 0x00, 0x01, 0x09, 0x00, 0xE5, 0x7F, 0x0B, 0x00, 0x03, 0x00, 0x0C, 0x00, 0xF3, 0x7F,
            0x09, 0x20, 0x00, 0x01, 0x0C, 0x00, 0xFD, 0x7F, 0x0B, 0x00, 0xF4, 0x7F, 0x0D, 0x00, 0x04, 0x00,
            0x0A, 0x10, 0x00, 0x01, 0x0D, 0x00, 0xF5, 0x7F, 0x03, 0x00, 0x03, 0x00, 0x0C, 0x00, 0xFC, 0x7F,
            0x0B, 0x00, 0x00, 0x01, 0x0C, 0x00, 0xFD, 0x7F, 0x03, 0x00, 0xE0, 0x7F, 0x01, 0x00, 0xE8, 0x7F,
            0x40, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x15, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
            0x00, 0xB0, 0x00, 0x01, 0x0E, 0x00, 0x06, 0x00, 0x0D, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x08, 0x00,
            0x01, 0xA0, 0x00, 0x01, 0x0E, 0x00, 0x16, 0x00, 0x0F, 0x00, 0x1B, 0x00, 0x0D, 0x00, 0xFA, 0x7F,
            0x02, 0x90, 0x00, 0x01, 0x03, 0x00, 0x06, 0x00, 0x10, 0x00, 0x13, 0x00, 0x0E, 0x00, 0xF8, 0x7F,
            0x03, 0x80, 0x00, 0x01, 0x03, 0x00, 0x06, 0x00, 0x07, 0x00, 0x20, 0x00, 0x10, 0x00, 0xFA, 0x7F,
            0x04, 0x70, 0x00, 0x01, 0x03, 0x00, 0xF1, 0x7F, 0x0D, 0x00, 0x03, 0x00, 0x07, 0x00, 0xFA, 0x7F,
            0x05, 0x60, 0x00, 0x01, 0x07, 0x00, 0xFD, 0x7F, 0x0D, 0x00, 0x0D, 0x00, 0x11, 0x00, 0x18, 0x00,
            0x06, 0x50, 0x00, 0x02, 0x0E, 0x00, 0x06, 0x00, 0x12, 0x00, 0x0C, 0x00, 0x0F, 0x00, 0xEA, 0x7F,
            0x07, 0x40, 0x00, 0x02, 0x0E, 0x00, 0xED, 0x7F, 0x10, 0x00, 0x0B, 0x00, 0x12, 0x00, 0xFA, 0x7F,
            0x08, 0x30, 0x00, 0x01, 0x0D, 0x00, 0xE5, 0x7F, 0x0F, 0x00, 0x03, 0x00, 0x11, 0x00, 0xF3, 0x7F,
            0x09, 0x20, 0x00, 0x01, 0x11, 0x00, 0xFD, 0x7F, 0x0F, 0x00, 0xF4, 0x7F, 0x12, 0x00, 0x04, 0x00,
            0x0A, 0x10, 0x00, 0x01, 0x12, 0x00, 0xF5, 0x7F, 0x10, 0x00, 0x03, 0x00, 0x11, 0x00, 0xFC, 0x7F,
            0x0B, 0x00, 0x00, 0x01, 0x11, 0x00, 0xFD, 0x7F, 0x10, 0x00, 0xE0, 0x7F, 0x07, 0x00, 0xE8, 0x7F,
            0x70, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x15, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
            0x00, 0xB0, 0x00, 0x01, 0x0D, 0x00, 0x06, 0x00, 0x13, 0x00, 0x0F, 0x00, 0x0C, 0x00, 0x08, 0x00,
            0x01, 0xA0, 0x00, 0x01, 0x0D, 0x00, 0x16, 0x00, 0x14, 0x00, 0x1B, 0x00, 0x13, 0x00, 0xFA, 0x7F,
            0x02, 0x90, 0x00, 0x01, 0x0C, 0x00, 0x06, 0x00, 0x11, 0x00, 0x13, 0x00, 0x0D, 0x00, 0xF8, 0x7F,
            0x03, 0x80, 0x00, 0x01, 0x0C, 0x00, 0x06, 0x00, 0x15, 0x00, 0x20, 0x00, 0x11, 0x00, 0xFA, 0x7F,
            0x04, 0x70, 0x00, 0x01, 0x0C, 0x00, 0xF1, 0x7F, 0x13, 0x00, 0x03, 0x00, 0x15, 0x00, 0xFA, 0x7F,
            0x05, 0x60, 0x00, 0x01, 0x15, 0x00, 0xFD, 0x7F, 0x13, 0x00, 0x0D, 0x00, 0x16, 0x00, 0x18, 0x00,
            0x06, 0x50, 0x00, 0x01, 0x0D, 0x00, 0x06, 0x00, 0x17, 0x00, 0x0C, 0x00, 0x14, 0x00, 0xEA, 0x7F,
            0x07, 0x40, 0x00, 0x01, 0x0D, 0x00, 0xED, 0x7F, 0x11, 0x00, 0x0B, 0x00, 0x17, 0x00, 0xFA, 0x7F,
            0x08, 0x30, 0x00, 0x02, 0x13, 0x00, 0xE5, 0x7F, 0x14, 0x00, 0x03, 0x00, 0x16, 0x00, 0xF3, 0x7F,
            0x09, 0x20, 0x00, 0x02, 0x16, 0x00, 0xFD, 0x7F, 0x14, 0x00, 0xF4, 0x7F, 0x17, 0x00, 0x04, 0x00,
            0x0A, 0x10, 0x00, 0x01, 0x17, 0x00, 0xF5, 0x7F, 0x11, 0x00, 0x03, 0x00, 0x16, 0x00, 0xFC, 0x7F,
            0x0B, 0x00, 0x00, 0x01, 0x16, 0x00, 0xFD, 0x7F, 0x11, 0x00, 0xE0, 0x7F, 0x15, 0x00, 0xE8, 0x7F,
            0xA0, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x15, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
            0x00, 0xB0, 0x00, 0x01, 0x07, 0x00, 0x06, 0x00, 0x15, 0x00, 0x0F, 0x00, 0x06, 0x00, 0x08, 0x00,
            0x01, 0xA0, 0x00, 0x01, 0x07, 0x00, 0x16, 0x00, 0x11, 0x00, 0x1B, 0x00, 0x15, 0x00, 0xFA, 0x7F,
            0x02, 0x90, 0x00, 0x01, 0x06, 0x00, 0x06, 0x00, 0x18, 0x00, 0x13, 0x00, 0x07, 0x00, 0xF8, 0x7F,
            0x03, 0x80, 0x00, 0x01, 0x06, 0x00, 0x06, 0x00, 0x19, 0x00, 0x20, 0x00, 0x18, 0x00, 0xFA, 0x7F,
            0x04, 0x70, 0x00, 0x01, 0x06, 0x00, 0xF1, 0x7F, 0x15, 0x00, 0x03, 0x00, 0x19, 0x00, 0xFA, 0x7F,
            0x05, 0x60, 0x00, 0x01, 0x19, 0x00, 0xFD, 0x7F, 0x15, 0x00, 0x0D, 0x00, 0x1A, 0x00, 0x18, 0x00,
            0x06, 0x50, 0x00, 0x01, 0x07, 0x00, 0x06, 0x00, 0x1B, 0x00, 0x0C, 0x00, 0x11, 0x00, 0xEA, 0x7F,
            0x07, 0x40, 0x00, 0x01, 0x07, 0x00, 0xED, 0x7F, 0x18, 0x00, 0x0B, 0x00, 0x1B, 0x00, 0xFA, 0x7F,
            0x08, 0x30, 0x00, 0x01, 0x15, 0x00, 0xE5, 0x7F, 0x11, 0x00, 0x03, 0x00, 0x1A, 0x00, 0xF3, 0x7F,
            0x09, 0x20, 0x00, 0x01, 0x1A, 0x00, 0xFD, 0x7F, 0x11, 0x00, 0xF4, 0x7F, 0x1B, 0x00, 0x04, 0x00,
            0x0A, 0x10, 0x00, 0x02, 0x1B, 0x00, 0xF5, 0x7F, 0x18, 0x00, 0x03, 0x00, 0x1A, 0x00, 0xFC, 0x7F,
            0x0B, 0x00, 0x00, 0x02, 0x1A, 0x00, 0xFD, 0x7F, 0x18, 0x00, 0xE0, 0x7F, 0x19, 0x00, 0xE8, 0x7F,
            0xD0, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x04, 0x15, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
            0x00, 0xB0, 0x00, 0x01, 0x01, 0x00, 0x06, 0x00, 0x1C, 0x00, 0x0F, 0x00, 0x1D, 0x00, 0x08, 0x00,
            0x01, 0xA0, 0x00, 0x01, 0x01, 0x00, 0x16, 0x00, 0x0C, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0xFA, 0x7F,
            0x02, 0x90, 0x00, 0x01, 0x1D, 0x00, 0x06, 0x00, 0x06, 0x00, 0x13, 0x00, 0x01, 0x00, 0xF8, 0x7F,
            0x03, 0x80, 0x00, 0x01, 0x1D, 0x00, 0x06, 0x00, 0x1E, 0x00, 0x20, 0x00, 0x06, 0x00, 0xFA, 0x7F,
            0x04, 0x70, 0x00, 0x02, 0x1D, 0x00, 0xF1, 0x7F, 0x1C, 0x00, 0x03, 0x00, 0x1E, 0x00, 0xFA, 0x7F,
            0x05, 0x60, 0x00, 0x02, 0x1E, 0x00, 0xFD, 0x7F, 0x1C, 0x00, 0x0D, 0x00, 0x1F, 0x00, 0x18, 0x00,
            0x06, 0x50, 0x00, 0x01, 0x01, 0x00, 0x06, 0x00, 0x15, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0xEA, 0x7F,
            0x07, 0x40, 0x00, 0x01, 0x01, 0x00, 0xED, 0x7F, 0x06, 0x00, 0x0B, 0x00, 0x15, 0x00, 0xFA, 0x7F,
            0x08, 0x30, 0x00, 0x01, 0x1C, 0x00, 0xE5, 0x7F, 0x0C, 0x00, 0x03, 0x00, 0x1F, 0x00, 0xF3, 0x7F,
            0x09, 0x20, 0x00, 0x01, 0x1F, 0x00, 0xFD, 0x7F, 0x0C, 0x00, 0xF4, 0x7F, 0x15, 0x00, 0x04, 0x00,
            0x0A, 0x10, 0x00, 0x01, 0x15, 0x00, 0xF5, 0x7F, 0x06, 0x00, 0x03, 0x00, 0x1F, 0x00, 0xFC, 0x7F,
            0x0B, 0x00, 0x00, 0x01, 0x1F, 0x00, 0xFD, 0x7F, 0x06, 0x00, 0xE0, 0x7F, 0x1E, 0x00, 0xE8, 0x7F,
            0xBF, 0x0E, 0x9C, 0x40, 0x5C, 0x8F, 0xA2, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0x5C, 0x8F, 0xA2, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0x5C, 0x8F, 0xA2, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0x5C, 0x8F, 0xA2, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0x5C, 0x8F, 0xA2, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0x5C, 0x8F, 0xA2, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0x5C, 0x8F, 0xA2, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0x5C, 0x8F, 0xA2, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x5C, 0x8F, 0xA2, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x5C, 0x8F, 0xA2, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x5C, 0x8F, 0xA2, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0x5C, 0x8F, 0xA2, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0x5C, 0x8F, 0xA2, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0x5C, 0x8F, 0xA2, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0x5C, 0x8F, 0xA2, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0x5C, 0x8F, 0xA2, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0x5C, 0x8F, 0xA2, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0x5C, 0x8F, 0xA2, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0x5C, 0x8F, 0xA2, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0x5C, 0x8F, 0xA2, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0x5C, 0x8F, 0xA2, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x5C, 0x8F, 0xA2, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x5C, 0x8F, 0xA2, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0x5C, 0x8F, 0xA2, 0xC0, 0xBF, 0x0E, 0x9C, 0x40, 0xBF, 0x0E, 0x9C, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x1F, 0x06, 0x0D, 0x41, 0x91, 0x91, 0x91, 0x00, 0x70, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0xA0, 0x32, 0xD2, 0x3D, 0xA0, 0x32, 0xD2, 0xBD, 0xA0, 0x32, 0xD2, 0xBD,
            0xF9, 0x2D, 0x0A, 0x41, 0x91, 0x91, 0x91, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0xA0, 0x32, 0xD2, 0xBD, 0xA0, 0x32, 0xD2, 0xBD, 0xEF, 0x3C, 0x09, 0x41,
            0x8F, 0x92, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0xF8, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
            0x0E, 0x4F, 0x9F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x04, 0xB9, 0xDC, 0x40, 0xB1, 0x04, 0xB1, 0x00,
            0x00, 0x00, 0x00, 0x00, 0xF0, 0xFB, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x0E, 0x4F, 0x9F, 0xC0, 0x04, 0xB9, 0xDC, 0x40, 0xB1, 0xB1, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00,
            0x34, 0xFA, 0xFF, 0xFF, 0x0E, 0x4F, 0x9F, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x04, 0xB9, 0xDC, 0x40, 0x04, 0xB1, 0xB1, 0x02, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xA0, 0x32, 0xD2, 0xBD, 0xA0, 0x32, 0xD2, 0x3D, 0xA0, 0x32, 0xD2, 0x3D, 0xF9, 0x2D, 0x0A, 0x41,
            0x91, 0x91, 0x91, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0xFC, 0xFF, 0xFF, 0x0E, 0x4F, 0x9F, 0xC0,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xB9, 0xDC, 0x40, 0x04, 0xB1, 0xB1, 0x03,
            0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x32, 0xD2, 0x3D,
            0xA0, 0x32, 0xD2, 0x3D, 0xEF, 0x3C, 0x09, 0x41, 0x8F, 0x92, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xF4, 0xF8, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x4F, 0x9F, 0x40,
            0x04, 0xB9, 0xDC, 0x40, 0xB1, 0xB1, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x78, 0xFA, 0xFF, 0xFF,
            0x00, 0x00, 0x00, 0x00, 0x0E, 0x4F, 0x9F, 0x40, 0x00, 0x00, 0x00, 0x00, 0x04, 0xB9, 0xDC, 0x40,
            0xB1, 0x04, 0xB1, 0x05, 0x73, 0x74, 0x61, 0x74, 0x69, 0x63, 0x73, 0x6F, 0x6C, 0x69, 0x64, 0x20,
            0x7B, 0x0A, 0x22, 0x69, 0x6E, 0x64, 0x65, 0x78, 0x22, 0x20, 0x22, 0x30, 0x22, 0x0A, 0x22, 0x63,
            0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x73, 0x22, 0x20, 0x22, 0x33, 0x33, 0x35, 0x37, 0x30, 0x38,
            0x31, 0x39, 0x22, 0x0A, 0x7D, 0x0A, 0x76, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x74, 0x65, 0x72,
            0x72, 0x61, 0x69, 0x6E, 0x20, 0x7B, 0x7D, 0x0A, 0x76, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x74,
            0x72, 0x69, 0x6D, 0x65, 0x73, 0x68, 0x65, 0x73, 0x20, 0x7B, 0x7D, 0x0A, 0x6D, 0x61, 0x74, 0x65,
            0x72, 0x69, 0x61, 0x6C, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x20, 0x7B, 0x0A, 0x22, 0x64, 0x65, 0x66,
            0x61, 0x75, 0x6C, 0x74, 0x22, 0x20, 0x22, 0x31, 0x22, 0x0A, 0x22, 0x64, 0x65, 0x66, 0x61, 0x75,
            0x6C, 0x74, 0x22, 0x20, 0x22, 0x32, 0x22, 0x0A, 0x7D, 0x0A, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
            0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        Titanfall::Bsp::physicsCollide_stub = { data.begin(), data.end() };
    }
    {  // GameLump
        constexpr std::array<uint8_t, 40> data = {
            0x01, 0x00, 0x00, 0x00, 0x70, 0x72, 0x70, 0x73, 0x00, 0x00, 0x0C, 0x00, 0x0C, 0x26, 0x0C, 0x00,
            0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        Titanfall::Bsp::gameLump_stub = { data.begin(), data.end() };
    }
    {  // World lights
        constexpr std::array<uint8_t, 200> data = {
            0x00, 0x00, 0x20, 0xC2, 0x00, 0x00, 0x20, 0x42, 0x00, 0x00, 0xD0, 0x42, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x52, 0x15, 0x3F, 0x66, 0x0E, 0xFE, 0xBE,
            0x5B, 0xA1, 0x24, 0xBF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x42, 0x00, 0x00, 0x40, 0x42, 0x00, 0x00, 0xD0, 0x42,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96, 0x43,
            0x00, 0x00, 0x80, 0x3F, 0x87, 0x40, 0xD5, 0xBB, 0x63, 0x89, 0x31, 0x37, 0x06, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        Titanfall::Bsp::worldLights_stub = { data.begin(), data.end() };
    }
    {  // Lightmap headers
        constexpr std::array<uint8_t, 8> data = {
            0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00
        };
        Titanfall::Bsp::lightmapHeaders_stub = { data.begin(), data.end() };
    }
    {  // CMUnique Contents
        constexpr std::array<uint8_t, 4> data = {
            0x01, 0x00, 0x00, 0x00
        };
        Titanfall::Bsp::cmUniqueContents_stub = { data.begin(), data.end() };
    }
    {  // LightMap Data Sky
        for (std::size_t i = 0; i < 524288; i++) {
            Titanfall::Bsp::lightMapDataSky_stub.emplace_back(0);
        }
    }
    {  // CSM AABB Nodes
        constexpr std::array<uint8_t, 32> data = {
            0x71, 0xFD, 0x3F, 0xC3, 0x71, 0xFD, 0x3F, 0xC3, 0x71, 0xFD, 0x3F, 0xC3, 0x00, 0x00, 0x00, 0x00,
            0x71, 0xFD, 0x3F, 0x43, 0x71, 0xFD, 0x3F, 0x43, 0x71, 0xFD, 0x3F, 0x43, 0x00, 0x00, 0x00, 0x00
        };
        Titanfall::Bsp::csmAABBNodes_stub = { data.begin(), data.end() };
    }
    {  // Cell BSP Nodes
        constexpr std::array<uint8_t, 8> data = {
            0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00
        };
        Titanfall::Bsp::cellBSPNodes_stub = { data.begin(), data.end() };
    }
    {  // Cells
        constexpr std::array<uint8_t, 8> data = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF
        };
        Titanfall::Bsp::cells_stub = { data.begin(), data.end() };
    }
}
