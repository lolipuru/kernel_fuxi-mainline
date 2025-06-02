// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2025 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>

#include <video/mipi_display.h>

#include <drm/display/drm_dsc.h>
#include <drm/display/drm_dsc_helper.h>
#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct m3_38_0c_0a_dsc {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct drm_dsc_config dsc;
	struct gpio_desc *reset_gpio;
};

static inline
struct m3_38_0c_0a_dsc *to_m3_38_0c_0a_dsc(struct drm_panel *panel)
{
	return container_of(panel, struct m3_38_0c_0a_dsc, panel);
}

static void m3_38_0c_0a_dsc_reset(struct m3_38_0c_0a_dsc *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(1000, 2000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
}

static int m3_38_0c_0a_dsc_on(struct m3_38_0c_0a_dsc *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9e,
				     0x11, 0x00, 0x00, 0x89, 0x30, 0x80, 0x09,
				     0xd8, 0x04, 0x38, 0x00, 0x28, 0x02, 0x1c,
				     0x02, 0x1c, 0x02, 0x00, 0x02, 0x3b, 0x00,
				     0x20, 0x03, 0x92, 0x00, 0x07, 0x00, 0x0e,
				     0x02, 0xe0, 0x02, 0x8b, 0x18, 0x00, 0x10,
				     0xf0, 0x03, 0x0c, 0x20, 0x00, 0x06, 0x0b,
				     0x0b, 0x33, 0x0e, 0x1c, 0x2a, 0x38, 0x46,
				     0x54, 0x62, 0x69, 0x70, 0x77, 0x79, 0x7b,
				     0x7d, 0x7e, 0x01, 0x02, 0x01, 0x00, 0x09,
				     0x40, 0x09, 0xbe, 0x19, 0xfc, 0x19, 0xfa,
				     0x19, 0xf8, 0x1a, 0x38, 0x1a, 0x78, 0x1a,
				     0xb6, 0x2a, 0xb6, 0x2a, 0xf4, 0x2a, 0xf4,
				     0x4b, 0x34, 0x63, 0x74, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9d, 0x01);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_dcs_set_column_address_multi(&dsi_ctx, 0x0000, 0x0437);
	mipi_dsi_dcs_set_page_address_multi(&dsi_ctx, 0x0000, 0x095f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x60, 0x08);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x30, 0xbd);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x16, 0xf2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf2, 0x01, 0x70);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf7, 0x0f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x36, 0xc5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x11);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x3a, 0xc5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x3f, 0x21);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x52, 0xc5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x3f, 0x21);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x0d, 0x94);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x94, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x28);
	mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x0000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf7, 0x0f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe5, 0x15);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x3d, 0xf4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf4, 0xf0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xed, 0x43, 0x49, 0x42, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x0a, 0xb1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb1, 0x18, 0x48, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x01, 0x64, 0x92);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x92, 0x70);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x02, 0x7e, 0x92);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x92, 0x0f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbb, 0x30);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf7, 0x0f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x20, 0xf6);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf6, 0xf0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x4e, 0x98);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x98, 0x00, 0x09, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x0f, 0xf6);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf6, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf7, 0x0f);
	mipi_dsi_msleep(&dsi_ctx, 20);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);

	return dsi_ctx.accum_err;
}

static int m3_38_0c_0a_dsc_off(struct m3_38_0c_0a_dsc *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x4e, 0x98);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x98, 0x01, 0x09, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00, 0x0f, 0xf6);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf6, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf7, 0x0f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_msleep(&dsi_ctx, 100);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int m3_38_0c_0a_dsc_prepare(struct drm_panel *panel)
{
	struct m3_38_0c_0a_dsc *ctx = to_m3_38_0c_0a_dsc(panel);
	struct device *dev = &ctx->dsi->dev;
	struct drm_dsc_picture_parameter_set pps;
	int ret;

	m3_38_0c_0a_dsc_reset(ctx);

	ret = m3_38_0c_0a_dsc_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	drm_dsc_pps_payload_pack(&pps, &ctx->dsc);

	ret = mipi_dsi_picture_parameter_set(ctx->dsi, &pps);
	if (ret < 0) {
		dev_err(panel->dev, "failed to transmit PPS: %d\n", ret);
		return ret;
	}

	ret = mipi_dsi_compression_mode(ctx->dsi, true);
	if (ret < 0) {
		dev_err(dev, "failed to enable compression mode: %d\n", ret);
		return ret;
	}

	msleep(28); /* TODO: Is this panel-dependent? */

	return 0;
}

static int m3_38_0c_0a_dsc_unprepare(struct drm_panel *panel)
{
	struct m3_38_0c_0a_dsc *ctx = to_m3_38_0c_0a_dsc(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = m3_38_0c_0a_dsc_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	return 0;
}

static const struct drm_display_mode m3_38_0c_0a_dsc_mode = {
	.clock = (1080 + 124 + 32 + 124) * (2400 + 128 + 24 + 132) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 124,
	.hsync_end = 1080 + 124 + 32,
	.htotal = 1080 + 124 + 32 + 124,
	.vdisplay = 2400,
	.vsync_start = 2400 + 128,
	.vsync_end = 2400 + 128 + 24,
	.vtotal = 2400 + 128 + 24 + 132,
	.width_mm = 66,
	.height_mm = 147,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int m3_38_0c_0a_dsc_get_modes(struct drm_panel *panel,
				     struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &m3_38_0c_0a_dsc_mode);
}

static const struct drm_panel_funcs m3_38_0c_0a_dsc_panel_funcs = {
	.prepare = m3_38_0c_0a_dsc_prepare,
	.unprepare = m3_38_0c_0a_dsc_unprepare,
	.get_modes = m3_38_0c_0a_dsc_get_modes,
};

static int m3_38_0c_0a_dsc_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int m3_38_0c_0a_dsc_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops m3_38_0c_0a_dsc_bl_ops = {
	.update_status = m3_38_0c_0a_dsc_bl_update_status,
	.get_brightness = m3_38_0c_0a_dsc_bl_get_brightness,
};

static struct backlight_device *
m3_38_0c_0a_dsc_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 4095,
		.max_brightness = 4095,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &m3_38_0c_0a_dsc_bl_ops, &props);
}

static int m3_38_0c_0a_dsc_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct m3_38_0c_0a_dsc *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	drm_panel_init(&ctx->panel, dev, &m3_38_0c_0a_dsc_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);
	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = m3_38_0c_0a_dsc_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	/* This panel only supports DSC; unconditionally enable it */
	dsi->dsc = &ctx->dsc;

	ctx->dsc.dsc_version_major = 1;
	ctx->dsc.dsc_version_minor = 1;

	/* TODO: Pass slice_per_pkt = 2 */
	ctx->dsc.slice_height = 40;
	ctx->dsc.slice_width = 540;
	/*
	 * TODO: hdisplay should be read from the selected mode once
	 * it is passed back to drm_panel (in prepare?)
	 */
	WARN_ON(1080 % ctx->dsc.slice_width);
	ctx->dsc.slice_count = 1080 / ctx->dsc.slice_width;
	ctx->dsc.bits_per_component = 8;
	ctx->dsc.bits_per_pixel = 8 << 4; /* 4 fractional bits */
	ctx->dsc.block_pred_enable = true;

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void m3_38_0c_0a_dsc_remove(struct mipi_dsi_device *dsi)
{
	struct m3_38_0c_0a_dsc *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id m3_38_0c_0a_dsc_of_match[] = {
	{ .compatible = "mdss,m3-38-0c-0a-dsc" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, m3_38_0c_0a_dsc_of_match);

static struct mipi_dsi_driver m3_38_0c_0a_dsc_driver = {
	.probe = m3_38_0c_0a_dsc_probe,
	.remove = m3_38_0c_0a_dsc_remove,
	.driver = {
		.name = "panel-m3-38-0c-0a-dsc",
		.of_match_table = m3_38_0c_0a_dsc_of_match,
	},
};
module_mipi_dsi_driver(m3_38_0c_0a_dsc_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for xiaomi m3 38 0c 0a sec cmd mode dsc dsi panel");
MODULE_LICENSE("GPL");
