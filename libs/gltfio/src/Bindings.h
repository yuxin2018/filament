/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GLTFIO_BINDINGS_H
#define GLTFIO_BINDINGS_H

namespace filament {
    class VertexBuffer;
    class IndexBuffer;
    class MaterialInstance;
    class TextureSampler;
}

namespace gltfio {

/**
 * Read-only structure that tells ResourceLoader how to load a source blob into a
 * filament::VertexBuffer, filament::IndexBuffer, etc.
 *
 * Each binding instance corresponds to one of the following:
 *
 * - One call to IndexBuffer::setBuffer().
 */
struct BufferBinding {
    const char* uri;
    uint32_t totalSize;
    uint32_t offset;
    uint32_t size;
    void** data;
    filament::IndexBuffer* indexBuffer;
    bool convertBytesToShorts;
};

/**
 * Read-only structure that describes a binding between filament::Texture and
 * filament::MaterialInstance.
 */
struct TextureBinding {
    const char* uri;
    uint32_t totalSize;
    const char* mimeType;
    void** data;
    size_t offset;
    filament::MaterialInstance* materialInstance;
    const char* materialParameter;
    filament::TextureSampler sampler;
    bool srgb;
};

} // namsepace gltfio

#endif // GLTFIO_BINDINGS_H
