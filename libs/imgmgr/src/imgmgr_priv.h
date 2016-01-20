/**
 * Copyright (c) 2015 Runtime Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __IMGMGR_PRIV_H_
#define __IMGMGR_PRIV_H_

#include <stdint.h>

/*
 * When accompanied by image, it's this structure followed by data.
 * Response contains just the offset.
 */
struct imgmgr_upload_cmd {
    uint32_t iuc_off;
};

/*
 * Response to list:
 * {
 *      "images":[ <version1>, <version2>]
 * }
 *
 *
 * Request to boot to version:
 * {
 *      "test":<version>
 * }
 *
 * Response to boot read:
 * {
 *	"test":<version>,
 *	"main":<version>,
 *      "active":<version>
 * }
 *
 * Request to upload:
 * {
 *      "off":<offset>,
 *      "data":<base64encoded binary>
 * }
 *
 * Response to upload:
 * {
 *      "off":<offset
 * }
 */

struct nmgr_hdr;
struct os_mbuf;

int imgr_boot_read(struct nmgr_hdr *nmr, struct os_mbuf *req,
  uint16_t srcoff, struct nmgr_hdr *rsp_hdr, struct os_mbuf *rsp);
int imgr_boot_write(struct nmgr_hdr *nmr, struct os_mbuf *req,
  uint16_t srcoff, struct nmgr_hdr *rsp_hdr, struct os_mbuf *rsp);

int imgr_read_ver(int area_id, struct image_version *ver);

#endif /* __IMGMGR_PRIV_H */