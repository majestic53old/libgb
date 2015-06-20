/**
 * libgb
 * Copyright (C) 2015 David Jolly
 * ----------------------
 *
 * libgb is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libgb is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GB_GPU_H_
#define GB_GPU_H_

namespace GB_NS {

	namespace GB_COMP_NS {

		typedef enum {
			GB_GPU_STATE_HBLNK = 0,
			GB_GPU_STATE_VBLNK,
			GB_GPU_STATE_OAM,
			GB_GPU_STATE_VRAM,
		} gb_gpu_st_t;

		#define GB_GPU_STATE_MAX GB_GPU_STATE_VRAM

		typedef class _gb_gpu {

			public:

				~_gb_gpu(void);

				static void _delete(void);

				static void _graphics(
					__in _gb_gpu *gpu
					);

				static _gb_gpu *acquire(void);

				void initialize(void);

				bool is_active(void);

				static bool is_allocated(void);

				bool is_initialized(void);

				void reset(void);

				void start(
					__in_opt const std::string &title = std::string(),
					__in_opt bool detach = false
					);

				void step(
					__in gbb_t last
					);

				void stop(void);

				std::string to_string(
					__in_opt bool verb = false
					);

				void uninitialize(void);

			protected:

				_gb_gpu(void);

				_gb_gpu(
					__in const _gb_gpu &other
					);

				_gb_gpu &operator=(
					__in const _gb_gpu &other
					);

				bool m_init;

				static _gb_gpu *m_inst;

				gb_mmu_ptr m_mmu;

			private:

				bool m_active, m_update;

				gb_buf_t m_buf;

				std::thread m_graphics_thread;

				gbb_t m_line;

				gb_gpu_st_t m_state;				

				uint32_t m_tot;

		} gb_gpu, *gb_gpu_ptr;
	}
}

#endif // GB_GPU_H_
