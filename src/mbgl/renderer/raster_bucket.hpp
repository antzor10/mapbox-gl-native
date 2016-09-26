#pragma once

#include <mbgl/renderer/bucket.hpp>
#include <mbgl/util/raster.hpp>
#include <mbgl/gl/context.hpp>

namespace mbgl {

class RasterShader;
class RasterVertex;
class StaticRasterVertexBuffer;
class VertexArrayObject;

namespace gl {
template <class> class VertexBuffer;
} // namespace gl

class RasterBucket : public Bucket {
public:
    void upload(gl::Context&) override;
    void render(Painter&, PaintParameters&, const style::Layer&, const RenderTile&) override;
    bool hasData() const override;
    bool needsClipping() const override;

    void setImage(PremultipliedImage);

    void drawRaster(RasterShader&, gl::VertexBuffer<RasterVertex>&, VertexArrayObject&, gl::Context&);

    Raster raster;
};

} // namespace mbgl
