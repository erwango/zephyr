/*
 * Copyright The Zephyr Project Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_MSPI_MSPI_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_MSPI_MSPI_H_

/**
 * @name MSPI memory map access enable
 * @brief Values for the "enable" cell of the memmap-config devicetree
 *        property. These must be kept in sync with struct mspi_memmap_cfg
 *        in include/zephyr/drivers/mspi.h.
 * @{
 */
#define MSPI_MEMMAP_DISABLED 0
#define MSPI_MEMMAP_ENABLED  1
/** @} */

/**
 * @name MSPI memory map access permission
 * @brief Values for the "permission" cell of the memmap-config devicetree
 *        property. These must be kept in sync with enum mspi_memmap_permit
 *        in include/zephyr/drivers/mspi.h.
 * @{
 */
#define MSPI_MEMMAP_READ_WRITE 0
#define MSPI_MEMMAP_READ_ONLY  1
/** @} */

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_MSPI_MSPI_H_ */
