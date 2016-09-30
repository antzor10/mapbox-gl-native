#pragma once

#include <mbgl/renderer/bucket.hpp>
#include <mbgl/util/raster.hpp>

namespace mbgl {

class RasterShader;
class RasterVertex;

namespace gl {
class Context;
template <class> class VertexBuffer;
class VertexArrayObject;
} // namespace gl

class RasterBucket : public Bucket {
public:
    void upload(gl::Context&) override;
    void render(Painter&, PaintParameters&, const style::Layer&, const RenderTile&) override;
    bool hasData() const override;
    bool needsClipping() const override;

    void setImage(PremultipliedImage);

    void drawRaster(RasterShader&, gl::VertexBuffer<RasterVertex>&, gl::VertexArrayObject&, gl::Context&);

    Raster raster;
};

} // namespace mbgl
